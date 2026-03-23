/******************************************************************************
Link: https://marisaoj.com/problem/214
Code: 214
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-26-18.46.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int nodes[MAXN * 4 + 5];
int n, q, A[MAXN + 5], B[MAXN + 5];

void push(int id, int l, int r){
    int mid = (l + r) >> 1;
    if(nodes[id] == 0) return;

    nodes[id << 1] = nodes[id];
    nodes[id << 1 | 1] = nodes[id] + mid + 1 - l;

    nodes[id] = 0;
}

void update(int id, int l, int r, int u, int v, int a){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id] = a + l - u;
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, a);
    update(id << 1 | 1, mid + 1, r, u, v, a);
}

int get(int id, int l, int r, int idx){
    if(idx < l || r < idx) return -1;
    if(l == r){
        return nodes[id];
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    if(idx <= mid) return get(id << 1, l, mid, idx);
    else return get(id << 1 | 1, mid + 1, r, idx);

    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    for(int i = 1; i <= n; ++i) cin >> B[i];

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x, y, k;
            cin >> x >> y >> k;

            update(1, 1, n, y, y + k - 1, x);
        }
        else{
            int i; cin >> i;
            int pos = get(1, 1, n, i);

            if(pos == 0) cout << B[i] << '\n';
            else cout << A[pos] << '\n';
        }
    }

    return 0;
}
