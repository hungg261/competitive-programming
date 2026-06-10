/******************************************************************************
Link: https://codeforces.com/problemset/problem/438/D
Code: 438D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-00.24.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int nodes[MAXN * 4 + 5], maxNodes[MAXN * 4 + 5];
int n, q;

void build(int id, int l, int r){
    if(l == r){
        cin >> nodes[id];
        maxNodes[id] = nodes[id];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    maxNodes[id] = max(maxNodes[id << 1], maxNodes[id << 1 | 1]);
}

void let(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] = val;
        maxNodes[id] = nodes[id];
        return;
    }

    int mid = (l + r) >> 1;
    let(id << 1, l, mid, idx, val);
    let(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    maxNodes[id] = max(maxNodes[id << 1], maxNodes[id << 1 | 1]);
}

void update(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u || maxNodes[id] < x) return;
    if(l == r){
        nodes[id] %= x;
        maxNodes[id] = nodes[id];
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, x);
    update(id << 1 | 1, mid + 1, r, u, v, x);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    maxNodes[id] = max(maxNodes[id << 1], maxNodes[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    build(1, 1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r;
            cin >> l >> r;

            cout << get(1, 1, n, l, r) << '\n';
        }
        else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;

            update(1, 1, n, l, r, x);
        }
        else{
            int k, x;
            cin >> k >> x;

            let(1, 1, n, k, x);
        }
    }

    return 0;
}
