/******************************************************************************
Link: https://coding.fit.hcmus.edu.vn/problem/express
Code: express
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-20-17.26.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
vector<int> values;

inline int f(int x, const vector<int>& vec = values){ return lower_bound(begin(vec), end(vec), x) - begin(vec) + 1; }
void compress(vector<int>& vec = values){
    sort(begin(vec), end(vec));
    vec.erase(unique(begin(vec), end(vec)), end(vec));
}

struct Range{
    int l, r;

    bool operator < (const Range& other) const {
        return l < other.l;
    }
} ranges[MAXN + 5];
int N;

namespace PST{

struct Node{
    int sum;
    Node *l, *r;

    Node(int _sum, Node *_l = nullptr, Node *_r = nullptr):
        sum(_sum), l(_l), r(_r){}
    Node(Node *_l = nullptr, Node *_r = nullptr): l(_l), r(_r){
        sum = (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};
Node* nodes[MAXN * 2 + 5];

Node* build(int l = 0, int r = N * 2){
    if(l == r) return new Node(0);

    int mid = (l + r) >> 1;
    Node *L = build(l, mid), *R = build(mid + 1, r);
    return new Node(L, R);
}

Node* update(Node* node, int idx, int val, int l = 0, int r = N * 2){
    if(l == r) return new Node(node->sum + val);

    int mid = (l + r) >> 1;
    if(idx <= mid)
        return new Node(update(node->l, idx, val, l, mid), node->r);
    else return new Node(node->l, update(node->r, idx, val, mid + 1, r));
}

int get(Node* node, int u, int v, int l = 0, int r = N * 2){
    if(!node || v < l || r < u) return 0;
    if(u <= l && r <= v) return node->sum;

    int mid = (l + r) >> 1;
    return get(node->l, u, v, l, mid) + get(node->r, u, v, mid + 1, r);
}

int query(int l, int r, int a, int b){
    return get(nodes[r], a, b) - get(nodes[l - 1], a, b);
}

}

void solve(){
    int Q; cin >> Q;

    int shift = 0;
    while(Q--){
        int L, R;
        cin >> L >> R;

        L += shift; R += shift;
        int l = f(L), r = f(R + 1) - 1;

        cout << (shift = PST::query(l, r, l, r)) << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> ranges[i].l >> ranges[i].r;

        values.push_back(ranges[i].l);
        values.push_back(ranges[i].r);
    }
    sort(ranges + 1, ranges + N + 1);
    compress();

    PST::nodes[0] = PST::build();
    int idx = 1;
    for(int i = 1; i <= N * 2; ++i){
        PST::nodes[i] = PST::nodes[i - 1];
        while(idx <= N && f(ranges[idx].l) == i){
            PST::nodes[i] = PST::update(PST::nodes[i], f(ranges[idx].r), 1);
            ++idx;
        }
    }

    solve();

    return 0;
}
