/******************************************************************************
Link: https://atcoder.jp/contests/abc357/tasks/abc357_f
Code: abc357_f
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-22-00.57.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
const int MOD = 998244353;
int nodes[2][MAXN * 4 + 5], lazy[2][MAXN * 4 + 5];

int arr[2][MAXN + 5], n, q;
int pre[2][MAXN + 5], preRes[MAXN + 5];

void apply(int o, int id, int l, int r, int val){
    nodes[o][id] += (pre[o][r] - pre[o][l - 1]) * val % MOD;
    nodes[o][id] %= MOD;

    lazy[o][id] += val;
    lazy[o][id] %= MOD;
}

void pull(int o, int id){
    nodes[o][id] = (nodes[o][id << 1] + nodes[o][id << 1 | 1]) % MOD;
}

void push(int o, int id, int l, int r){
    int mid = (l + r) >> 1;
    int& lz = lazy[o][id];

    apply(o, id << 1, l, mid, lz);
    apply(o, id << 1 | 1, mid + 1, r, lz);

    lz = 0;
}

void add(int o, int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(o, id, l, r, val);
        return;
    }

    push(o, id, l, r);

    int mid = (l + r) >> 1;
    add(o, id << 1, l, mid, u, v, val);
    add(o, id << 1 | 1, mid + 1, r, u, v, val);
    pull(o, id);
}

int get(int o, int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[o][id] % MOD;

    push(o, id, l, r);

    int mid = (l + r) >> 1;
    return (get(o, id << 1, l, mid, u, v) + get(o, id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) cin >> arr[0][i];
    for(int i = 1; i <= n; ++i) cin >> arr[1][i];
    for(int i = 1; i <= n; ++i){
        pre[0][i] = (pre[0][i - 1] + arr[0][i]) % MOD;
        pre[1][i] = (pre[1][i - 1] + arr[1][i]) % MOD;
        preRes[i] = (preRes[i - 1] + arr[0][i] * arr[1][i] % MOD) % MOD;
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;

            add(1, 1, 1, n, l, r, x);
        }
        else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;

            add(0, 1, 1, n, l, r, x);
        }
        else{
            int l, r;
            cin >> l >> r;

            int co0 = get(0, 1, 1, n, l, r),
                co1 = get(1, 1, 1, n, l, r);

            cerr << "co: " << co0 << ' ' << co1 << '\n';
            cout << (preRes[r] - preRes[l - 1] + co0 + co1) % MOD << '\n';
        }
    }

    return 0;
}
