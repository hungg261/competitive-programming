/******************************************************************************
Link: https://codeforces.com/contest/1107/problem/G
Code: 1107G
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-25-14.56.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5;
int n, a;
int d[MAXN + 5], c[MAXN + 5];

pair<int, int> nodes[MAXN * 4 + 5];
void build(int id, int l, int r){
    if(l >= r){
        nodes[id] = {d[l + 1] - d[l], l};
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
}

pair<int, int> get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return {-1, -1};
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int pow2(int x){ return x * x; }

struct Node{
    int maxPre, maxSuf, maxSum, sum;

    Node() = default;
    Node(int val){
        maxPre = max(0LL, val);
        maxSuf = max(0LL, val);
        maxSum = max(0LL, val);
        sum = val;
    }

    Node operator + (const Node& other){
        Node res;
        res.maxPre = max(maxPre, sum + other.maxPre);
        res.maxSuf = max(other.maxSuf, other.sum + maxSuf);
        res.sum = sum + other.sum;
        return res;
    }
};

Node solve(int l, int r){
    if(l > r) return Node(0);
    else if(l == r)
        return Node(a - c[l]);

    int mid = get(1, 1, n - 1, l, r - 1).second;

    Node L = solve(l, mid), R = solve(mid + 1, r);
    Node res = L + R;
    res.maxSum = max({L.maxSum, R.maxSum, L.maxSuf + R.maxPre - pow2(d[mid + 1] - d[mid])});

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a;
    for(int i = 1; i <= n; ++i){
        cin >> d[i] >> c[i];
    }

    build(1, 1, n - 1);
    cout << solve(1, n).maxSum << "\n";

    return 0;
}
