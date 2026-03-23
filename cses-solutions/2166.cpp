#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
    credit: hungg261 (me)
    template segment tree (v2)
*/
struct SegmentTree{
    struct Node{
        int value;
        int best;

        Node(){ value = 0; best = 0; }
        Node(int x, int y){ value = x; best = y; }

        static Node mergeNodes(Node&u, Node& v){
            Node res;
            res.value = u.value + v.value;
            res.best = max(u.best, u.value + v.best);

            return res;
        }
    };

    vector<int> arr;
    vector<Node> Nodes;
    int n;

    SegmentTree(int sz){ n = sz; arr.resize(n + 1); Nodes.resize(n * 4 + 1); }

    void build(int id, int l, int r){
        if(l == r){
            Nodes[id].value = arr[l];
            Nodes[id].best = max(0LL, arr[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        Nodes[id] = Node::mergeNodes(Nodes[id * 2], Nodes[id * 2 + 1]);
    }

    void update(int id, int l, int r, int idx, int x){
        if(r < idx || idx < l){
            return;
        }

        if(l == r){
            Nodes[id].value = x;
            Nodes[id].best = max(0LL, x);
            return;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, idx, x);
        update(id * 2 + 1, mid + 1, r, idx, x);
        Nodes[id] = Node::mergeNodes(Nodes[id * 2], Nodes[id * 2 + 1]);
    }

    Node get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return Node(0, 0);
        if(u <= l && r <= v) return Nodes[id];

        int mid = (l + r) / 2;
        Node Lnode = get(id * 2, l, mid, u, v), Rnode = get(id * 2 + 1, mid + 1, r, u, v);
        return Node::mergeNodes(Lnode, Rnode);
    }

    void build(){ build(1, 1, n); }
    void update(int k, int u){ update(1, 1, n, k, u); }
    Node get(int u, int v){ return get(1, 1, n, u, v); }

    int& operator[] (int idx){ return arr[idx]; }
    int operator[] (int idx) const{ return arr[idx]; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    SegmentTree segtree(n);

    for(int i = 1; i <= n; ++i){
        cin >> segtree[i];
    }
    segtree.build();

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int k, u;
            cin >> k >> u;

            segtree.update(k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            cout << segtree.get(a, b).best << '\n';
        }
    }

    return 0;
}
