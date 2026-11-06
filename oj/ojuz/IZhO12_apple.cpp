/******************************************************************************
Link: https://oj.uz/problem/view/IZhO12_apple
Code: IZhO12_apple
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-06-10.09.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

struct Node{
    int lc, rc;
    int sum, lazy;

    Node(){
        lc = rc = sum = 0;
        lazy = false;
    }
};
vector<Node> nodes = {Node(), Node()};

int new_node(){
    nodes.push_back(Node());
    return (int)nodes.size() - 1;
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

void apply(int id, int l, int r){
    nodes[id].sum = r - l + 1;
    nodes[id].lazy = true;
}

void push(int id, int l, int r){
    int lz = nodes[id].lazy;
    if(!lz) return;

    int mid = (l + r) >> 1;
    make::left(id);
    make::right(id);

    apply(nodes[id].lc, l, mid);
    apply(nodes[id].rc, mid + 1, r);

    nodes[id].lazy = false;
}

void pull(int id){
    int lc = nodes[id].lc;
    int rc = nodes[id].rc;
    nodes[id].sum = (lc ? nodes[lc].sum : 0) + (rc ? nodes[rc].sum : 0);
}

void update(int u, int v, int id = 1, int l = 1, int r = MAX){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, l, r);
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    if(u <= mid){
        if(!nodes[id].lc) make::left(id);
        update(u, v, nodes[id].lc, l, mid);
    }
    if(v > mid){
        if(!nodes[id].rc) make::right(id);
        update(u, v, nodes[id].rc, mid + 1, r);
    }

    pull(id);
}

int get(int u, int v, int id = 1, int l = 1, int r = MAX){
    if(!id || v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id].sum;

    push(id, l, r);

    int mid = (l + r) >> 1;
    return get(u, v, nodes[id].lc, l, mid) + get(u, v, nodes[id].rc, mid + 1, r);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    int C = 0;
    while(q--){
        int type, l, r;
        cin >> type >> l >> r;

        l += C;
        r += C;

        if(type == 2){
            update(l, r);
        }
        else{
            C = get(l, r);
            cout << C << "\n";
        }
    }

    return 0;
}
