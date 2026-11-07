/******************************************************************************
Link: https://codeforces.com/contest/915/problem/E
Code: 915E
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-06-20.24.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int n;

struct Node{
    int lc, rc;
    int sum;
    char lazy;

    Node(){
        lc = rc = sum = 0;
        lazy = -1;
    }
};
vector<Node> nodes = {Node(), Node()};
vector<int> garbage;

int new_node(){
    if(!garbage.empty()){
        int id = garbage.back();
        garbage.pop_back();
        nodes[id] = Node();
        return id;
    }
    nodes.push_back(Node());
    return (int)nodes.size() - 1;
}

void collect(int id){
    if(!id) return;
    garbage.push_back(id);
    collect(nodes[id].lc);
    collect(nodes[id].rc);
}

namespace make{

void left(int id){
    if(!nodes[id].lc){
        int nxt = new_node();
        nodes[id].lc = nxt;
    }
}

void right(int id){
    if(!nodes[id].rc){
        int nxt = new_node();
        nodes[id].rc = nxt;
    }
}

}

void apply(int id, int l, int r, int lz){
    nodes[id].sum = lz * (r - l + 1);
    nodes[id].lazy = lz;
}

void push(int id, int l, int r){
    int lz = nodes[id].lazy;
    if(lz == -1) return;

    int mid = (l + r) >> 1;
    make::left(id);
    make::right(id);

    apply(nodes[id].lc, l, mid, lz);
    apply(nodes[id].rc, mid + 1, r, lz);

    nodes[id].lazy = -1;
}

void pull(int id){
    int lc = nodes[id].lc;
    int rc = nodes[id].rc;
    nodes[id].sum = (lc ? nodes[lc].sum : 0) + (rc ? nodes[rc].sum : 0);
}

void update(int u, int v, int val, int id = 1, int l = 1, int r = n){
    if(v < l || r < u) return;
    if(nodes[id].sum == val * (r - l + 1)) return;
    if(u <= l && r <= v){
        apply(id, l, r, val);

        collect(nodes[id].lc); nodes[id].lc = 0;
        collect(nodes[id].rc); nodes[id].rc = 0;
        return;
    }


    push(id, l, r);

    int mid = (l + r) >> 1;
    if(u <= mid){
        if(!nodes[id].lc) make::left(id);
        update(u, v, val, nodes[id].lc, l, mid);
    }
    if(v > mid){
        if(!nodes[id].rc) make::right(id);
        update(u, v, val, nodes[id].rc, mid + 1, r);
    }

    pull(id);
}

int get(int u, int v, int id = 1, int l = 1, int r = n){
    if(!id || v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id].sum;

    push(id, l, r);

    int mid = (l + r) >> 1;
    return get(u, v, nodes[id].lc, l, mid) + get(u, v, nodes[id].rc, mid + 1, r);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    nodes.reserve(12'500'000);

    int q;
    cin >> q;

    while(q--){
        int type, l, r;
        cin >> l >> r >> type;

        if(type == 1){
            update(l, r, 1);
        }
        else{
            update(l, r, 0);
        }

        cout << n - get(1, n) << "\n";
    }

    return 0;
}
