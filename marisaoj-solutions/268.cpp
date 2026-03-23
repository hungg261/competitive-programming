/******************************************************************************
Link: https://marisaoj.com/problem/268
Code: 268
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-11-11.34.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int MAXN = 1e5;
struct Node{
    int mn = INF, mx = -INF, lazy = 0;

    Node operator + (const Node& other) const{
        Node res;
        res.mn = min(mn, other.mn);
        res.mx = max(mx, other.mx);
        res.lazy = 0;
        return res;
    }

    void apply(int lz){
        mn += lz;
        mx += lz;
        lazy += lz;
    }

    bool valid(){
        return mn == mx;
    }
} nodes[MAXN * 4 + 5];

void build(int id, int l, int r){
    if(l == r){
        nodes[id].mn = nodes[id].mx = 0;
        nodes[id].lazy = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void down(int id){
    int &lz = nodes[id].lazy;
    if(lz == 0) return;

    nodes[id << 1].apply(lz);
    nodes[id << 1 | 1].apply(lz);

    lz = 0;
}

void add(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id].apply(x);
        return;
    }

    down(id);

    int mid = (l + r) >> 1;
    add(id << 1, l, mid, u, v, x);
    add(id << 1 | 1, mid + 1, r, u, v, x);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return Node();
    if(u <= l && r <= v) return nodes[id];

    down(id);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int n, q;
map<int, int> mp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    build(1, 1, n);
    while(q--){
        int type; cin >> type;

        if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;

            if(!mp.count(x)) mp[x] = rng();
            add(1, 1, n, l, r, mp[x]);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << (get(1, 1, n, l, r).valid() ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
