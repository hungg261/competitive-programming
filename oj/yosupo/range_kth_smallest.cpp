/******************************************************************************
Link: https://judge.yosupo.jp/problem/range_kth_smallest
Code: range_kth_smallest
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-15-14.34.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, q, a[MAXN + 5];

struct Node{
    int sum;
    Node *l, *r;

    Node(int _sum, Node *_l = nullptr, Node *_r = nullptr):
        sum(_sum), l(_l), r(_r){}
    Node(Node *_l, Node *_r):
        sum((_l ? _l->sum : 0) + (_r ? _r->sum : 0)), l(_l), r(_r){}
};

Node *build(int id = 1, int l = 1, int r = n){
    if(l == r) return new Node(a[l]);

    int mid = (l + r) >> 1;
    return new Node(build(id << 1, l, mid),
                    build(id << 1 | 1, mid + 1, r));
}

Node *update(Node *node, int idx, int val, int id = 1, int l = 1, int r = n){
    if(!node) node = new Node(0);
    if(l == r) return new Node(node->sum + val);

    int mid = (l + r) >> 1;
    if(idx <= mid) return new Node(update(node->l, idx, val, id << 1, l, mid),
                                   node->r);
    else return new Node(node->l, update(node->r, idx, val, id << 1 | 1, mid + 1, r));
}

int get(Node *node, int u, int v, int id = 1, int l = 1, int r = n){
    if(!node || v < l || r < u) return 0;
    if(u <= l && r <= v) return node->sum;

    int mid = (l + r) >> 1;
    return get(node->l, u, v, id << 1, l, mid)
        + get(node->r, u, v, id << 1 | 1, mid + 1, r);
}

int walk(Node *node1, Node *node2, int k, int id = 1, int l = 1, int r = n){
    if(l == r) return l;

    int mid = (l + r) >> 1;
    int left = node2->l->sum - node1->l->sum;
    if(k <= left) return walk(node1->l, node2->l, k, id << 1, l, mid);
    else return walk(node1->r, node2->r, k - left, id << 1 | 1, mid + 1, r);
}

vector<int> values;
vector<Node*> nodes;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }

    sort(begin(values), end(values));

    nodes.push_back(build());
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(begin(values), end(values), a[i]) - begin(values) + 1;
        nodes.push_back(update(nodes.back(), a[i], 1));
    }

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        ++l; ++r; --r; ++k;
        cout << values[walk(nodes[l - 1], nodes[r], k) - 1] << "\n";
    }

    return 0;
}
