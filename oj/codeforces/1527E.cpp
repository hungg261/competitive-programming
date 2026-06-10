/******************************************************************************
Link: https://codeforces.com/contest/1527/problem/E
Code: 1527E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-00.13.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define GETCHAR _getchar_nolock
#else
#define GETCHAR getchar_unlocked
#endif

inline int readInt() {
    int x = 0;
    char ch = GETCHAR();
    while (ch < '0' || ch > '9') {
        if (ch == EOF) return -1;
        ch = GETCHAR();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = GETCHAR();
    }
    return x;
}

struct Node{
    int value;
    Node *l, *r;

    Node(int _value = 0): value(_value), l(NULL), r(NULL){}
    Node(Node *_l, Node *_r): value(_l->value + _r->value), l(_l), r(_r){}
    Node(Node *node): value(node->value), l(node->l), r(node->r){}
};

const int MAXN = 35000, MAXK = 100;
int arr[MAXN + 5], n, k, nxt[MAXN + 5];
Node* nodes[MAXN + 5];

Node *build(int l, int r){
    if(l == r){
        return new Node((int)0);
    }

    int mid = (l + r) >> 1;
    return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int l, int r, int idx, int val){
    if(l == r){
        return new Node((int)node->value + val);
    }

    int mid = (l + r) >> 1;
    if(idx <= mid) return new Node(update(node->l, l, mid, idx, val), node->r);
    else return new Node(node->l, update(node->r, mid + 1, r, idx, val));
}

int get(Node *node, int l, int r, int u, int v){
    if(!node || r < u || v < l) return 0;
    if(u <= l && r <= v) return node->value;

    int mid = (l + r) >> 1;
    return get(node->l, l, mid, u, v) + get(node->r, mid + 1, r, u, v);
}

int cost(int l, int r){
    return get(nodes[n], 1, n, 1, r) - get(nodes[l - 1], 1, n, 1, r);
}

int dp[MAXK + 5][MAXN + 5];

void computeDp(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MAX, -1};

    int curCost = cost(optL, mid);
    for(int i = optL; i <= min(optR, mid); ++i){
        best = min(best, {dp[c - 1][i - 1] + curCost, i});
        if(nxt[i] != -1 && nxt[i] <= mid) curCost -= nxt[i] - i;
    }

    dp[c][mid] = best.first;
    int opt = best.second;

    computeDp(c, l, mid - 1, optL, opt);
    computeDp(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c){
        computeDp(c, 1, n, 1, n);
    }
    cout << dp[k][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    n = readInt();
    k = readInt();
    for(int i = 1; i <= n; ++i){
        arr[i] = readInt();
    }

    vector<int> last(n + 1, -1);
    for(int i = n; i >= 1; --i){
        if(last[arr[i]] != 0){
            nxt[i] = last[arr[i]];
        }
        else nxt[i] = -1;

        last[arr[i]] = i;
    }

    nodes[0] = build(1, n);
    for(int i = 1; i <= n; ++i){
        nodes[i] = nodes[i - 1];
        if(nxt[i] != -1)
            nodes[i] = update(nodes[i], 1, n, nxt[i], nxt[i] - i);
    }

    solve();

    return 0;
}
