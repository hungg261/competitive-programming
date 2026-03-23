/******************************************************************************
Link: https://oj.vnoi.info/problem/segtree_itladder
Code: segtree_itladder
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-23-20.36.36
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;
int nodes[MAXN * 4 + 5], lazy1[MAXN * 4 + 5], lazy2[MAXN * 4 + 5];

void apply(int id, int l, int r, int val1, int val2){
    val1 %= MOD;
    val2 %= MOD;

    nodes[id] += val1 * (r - l + 1) % MOD;
    nodes[id] += (l + r) * (r - l + 1) / 2 * val2 % MOD;

    lazy1[id] += val1;
    lazy2[id] += val2;

    nodes[id] %= MOD;
    lazy1[id] %= MOD;
    lazy2[id] %= MOD;
}

void push(int id, int l, int r){
    int mid = (l + r) >> 1;
    int &lz1 = lazy1[id], &lz2 = lazy2[id];

    apply(id << 1, l, mid, lz1, lz2);
    apply(id << 1 | 1, mid + 1, r, lz1, lz2);

    lz1 = lz2 = 0;
}

void update(int id, int l, int r, int u, int v, int A, int B){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, l, r, -u * A + B, A);
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, A, B);
    update(id << 1 | 1, mid + 1, r, u, v, A, B);
    nodes[id] = (nodes[id << 1] + nodes[id << 1 | 1]) % MOD;
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id] % MOD;

    push(id, l, r);

    int mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int L, R, A, B;
            cin >> L >> R >> A >> B;

            update(1, 1, n, L, R, A, B);
        }
        else{
            int L, R;
            cin >> L >> R;

            int res = (get(1, 1, n, L, R) + MOD) % MOD;
            cout << res << '\n';
        }
    }

    return 0;
}
