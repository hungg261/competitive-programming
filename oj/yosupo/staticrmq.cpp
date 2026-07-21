/******************************************************************************
Link: https://judge.yosupo.jp/problem/staticrmq
Code: staticrmq
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-21-17.07.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int a[MAXN], n;

int nodes[MAXN * 4 + 5];
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

int get(int u, int v, int id = 1, int l = 0, int r = n - 1){
    if(v < l || r < u) return INT_MAX;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return min(get(u, v, id << 1, l, mid),
               get(u, v, id << 1 | 1, mid + 1, r));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    build();

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << get(l, r - 1) << "\n";
    }

    return 0;
}
