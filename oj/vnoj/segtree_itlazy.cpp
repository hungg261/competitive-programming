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
        int lazy = 0;

        Node() = default;
        Node(int x){ value = x; }

        void apply(int delta){
            value += delta;
            lazy += delta;
        }

        static Node mergeNodes(const Node& u, const Node& v){
            Node res;
            res.value = max(u.value, v.value);

            return res;
        }

        static Node Identity(){ return Node(LLONG_MIN / 2); }
    };


    vector<Node> Nodes;
    vector<int> arr;
    int n;

    SegmentTree() = default;
    SegmentTree(int sz){ n = sz; arr.resize(sz + 1); Nodes.resize(sz * 4 + 1); }

    void push(int id){
        int t = Nodes[id].lazy;
        if(t == 0) return;

        Nodes[id * 2].apply(t);
        Nodes[id * 2 + 1].apply(t);

        Nodes[id].lazy = 0;
    }

    void build(int id, int l, int r){
        if(l == r){
            Nodes[id].value = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        Nodes[id] = Node::mergeNodes(Nodes[id * 2], Nodes[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int v, int x){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            Nodes[id].apply(x);
            return;
        }

        int mid = (l + r) / 2;
        push(id);
        update(id * 2, l, mid, u, v, x);
        update(id * 2 + 1, mid + 1, r, u, v, x);
        Nodes[id] = Node::mergeNodes(Nodes[id * 2], Nodes[id * 2 + 1]);
    }

    Node get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return Node::Identity();
        if(u <= l && r <= v){
            return Nodes[id];
        }

        int mid = (l + r) / 2;
        push(id);

        Node Lnode = get(id * 2, l, mid, u, v),
            Rnode = get(id * 2 + 1, mid + 1, r, u, v);
        return Node::mergeNodes(Lnode, Rnode);
    }

    void build(){ build(1, 1, n); }
    void update(int idx, int x){ update(1, 1, n, idx, idx, x); }
    void update(int u, int v, int x){ update(1, 1, n, u, v, x); }
    Node get(int u, int v){ return get(1, 1, n, u, v); }

    void change(int idx, int val){
        int delta = val - arr[idx];
        arr[idx] = val;

        update(idx, delta);
    }

    int& operator[] (int idx){ return arr[idx]; }
    int operator[] (int idx) const{ return arr[idx]; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    SegmentTree segtree(n);
    for(int i = 1; i <= n; ++i){
        cin >> segtree[i];
    }
    segtree.build();

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x, y, val;
            cin >> x >> y >> val;

            segtree.update(x, y, val);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << segtree.get(l, r).value << '\n';
        }
    }

//    int n, q;
//    cin >> n >> q;
//
//    SegmentTree segtree(n + 1);
//
//    segtree.a[1] = 0;
//    for(int i = 1; i <= n; ++i){
//        int cur; cin >> cur;
//        segtree.a[i + 1] = segtree.a[i] + cur;
//    }
//    segtree.build();
//
//    while(q--){
//        int type; cin >> type;
//        if(type == 1){
//            int k, u;
//            cin >> k >> u;
//            ++k;
//
//            int diff = u - segtree.a[k];
//            segtree.a[k] = u;
//
//            segtree.update(k, n + 1, diff);
//        }
//        else{
//            int a, b;
//            cin >> a >> b;
//
//            ++a; ++b;
//
//            cout << segtree.get(a - 1, b).value - segtree.get(a - 1, a - 1).value << '\n';
//        }
//    }

    return 0;
}
