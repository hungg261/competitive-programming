/******************************************************************************
Link: https://codeforces.com/problemset/problem/915/E
Code: 915E
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-23-10.32.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> values;
inline int f(int x){ return lower_bound(begin(values) + 1, end(values), x) - begin(values); }

struct SegmentTree{
    struct Node{
        int val, lazy;

        Node(int _val = 0, int _lazy = 0): val(_val), lazy(_lazy){}

        Node operator + (const Node &other) const {
            return {val + other.val, -1};
        }
    };
    int n;
    vector<Node> nodes;

    SegmentTree() = default;
    SegmentTree(int _n): n(_n){
        nodes.resize(n * 4 + 5, Node());
    }

    void apply(int id, int l, int r, int lz){
        nodes[id].val = lz * (values[r + 1] - values[l]);
        nodes[id].lazy = lz;
    }

    void push(int id, int l, int r){
        int &lz = nodes[id].lazy;
        if(lz == -1) return;

        int mid = (l + r) >> 1;

        apply(id << 1, l, mid, lz);
        apply(id << 1 | 1, mid + 1, r, lz);

        lz = -1;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            apply(id, l, r, val);
            return;
        }

        push(id, l, r);

        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    }

    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return nodes[id].val;

        push(id, l, r);

        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
};

struct Query{
    int l, r, k;
    friend istream& operator >> (istream &is, Query &qr){
        return is >> qr.l >> qr.r >> qr.k;
    }
};
vector<Query> Q;
int n, q;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    Q.resize(q + 1);
    for(int i = 1; i <= q; ++i){
        cin >> Q[i];
        values.push_back(Q[i].l);
        values.push_back(Q[i].r);
        values.push_back(Q[i].r + 1);
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    int M = values.size();
    values.insert(begin(values), 0);

    SegmentTree ST(M);

    for(int i = 1; i <= q; ++i){
        int l = f(Q[i].l), r = f(Q[i].r + 1) - 1;
        if(Q[i].k == 1){
            if(l <= r) ST.update(1, 1, M - 1, l, r, 1);
        }
        else{
            if(l <= r) ST.update(1, 1, M - 1, l, r, 0);
        }

        cout << n - ST.get(1, 1, M - 1, 1, M - 1) << "\n";
    }

    return 0;
}
