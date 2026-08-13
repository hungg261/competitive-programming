/******************************************************************************
Link: https://judge.yosupo.jp/problem/range_add_range_min
Code: range_add_range_min
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-16.51.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;
int n, q, a[MAXN + 5];

int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];
void build(int id = 1, int l = 0, int r = n - 1){
    if(l == r){
        nodes[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

void apply(int id, int lz){
    nodes[id] += lz;
    lazy[id] += lz;
}

void push(int id){
    int lz = lazy[id];
    if(lz == 0) return;

    apply(id << 1, lz);
    apply(id << 1 | 1, lz);

    lazy[id] = 0;
}

void add(int u, int v, int val, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, val);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    add(u, v, val, id << 1, l, mid);
    add(u, v, val, id << 1 | 1, mid + 1, r);
    nodes[id] = min(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int u, int v, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return LLONG_MAX;
    if(u <= l && r <= v) return nodes[id];

    push(id);

    int mid = (l + r) >> 1;
    return min(get(u, v, id << 1, l, mid),
               get(u, v, id << 1 | 1, mid + 1, r));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    build();

    while(q--){
        int type;
        cin >> type;

        if(type == 0){
            int l, r, x;
            cin >> l >> r >> x;

            add(l, r - 1, x);
        }
        else if(type == 1){
            int l, r;
            cin >> l >> r;

            cout << get(l, r - 1) << "\n";
        }
    }

    return 0;
}
