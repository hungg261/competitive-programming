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
            res.value = min(u.value, v.value);

            return res;
        }

        static Node Identity(){ return Node(LLONG_MAX / 2); }
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

    void increase(int id, int l, int r, int u, int v, int x){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            Nodes[id].apply(x);
            return;
        }

        int mid = (l + r) / 2;
        push(id);
        increase(id * 2, l, mid, u, v, x);
        increase(id * 2 + 1, mid + 1, r, u, v, x);
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
    void increase(int idx, int x){ increase(1, 1, n, idx, idx, x); }
    void increase(int u, int v, int x){ increase(1, 1, n, u, v, x); }
    Node get(int u, int v){ return get(1, 1, n, u, v); }

    void update(int idx, int val){
        int delta = val - arr[idx];
        arr[idx] = val;

        increase(idx, delta);
    }

    int& operator[] (int idx){ return arr[idx]; }
    int operator[] (int idx) const{ return arr[idx]; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;

    SegmentTree smaller(n), larger(n);
    for(int i = 1; i <= n; ++i){
        int p; cin >> p;

        smaller[i] = p - i;
        larger[i] = p + i;
    }
    smaller.build();
    larger.build();

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int k, x;
            cin >> k >> x;

            smaller.update(k, x - k);
            larger.update(k, x + k);
        }
        else{
            int k; cin >> k;

            int L = smaller.get(1, k - 1).value + k, R = larger.get(k, n).value - k;
            int ans = min(L, R);

            cout << ans << '\n';
        }
    }

    return 0;
}
