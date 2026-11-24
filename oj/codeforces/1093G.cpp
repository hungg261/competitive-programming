/******************************************************************************
Link: https://codeforces.com/problemset/problem/1093/G
Code: 1093G
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-24-19.14.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXK = 5;
int n, k, a[MAXN + 5][MAXK];
int nodes[2][1 << MAXK][MAXN * 4 + 5];

int f(int i, int mask = -1){
    int cur = 0;
    for(int j = 0; j < k; ++j){
        if(mask >> j & 1) cur += a[i][j];
        else cur -= a[i][j];
    }
    return cur;
}

void build(int mask, int id = 1, int l = 1, int r = n){
    if(l == r){
        nodes[0][mask][id] = nodes[1][mask][id] = f(l, mask);
        return;
    }

    int mid = (l + r) >> 1;
    build(mask, id << 1, l, mid);
    build(mask, id << 1 | 1, mid + 1, r);

    nodes[0][mask][id] = min(nodes[0][mask][id << 1], nodes[0][mask][id << 1 | 1]);
    nodes[1][mask][id] = max(nodes[1][mask][id << 1], nodes[1][mask][id << 1 | 1]);
}

void update(int mask, int idx, int id = 1, int l = 1, int r = n){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[0][mask][id] = nodes[1][mask][id] = f(idx, mask);
        return;
    }

    int mid = (l + r) >> 1;
    if(idx <= mid) update(mask, idx, id << 1, l, mid);
    else update(mask, idx, id << 1 | 1, mid + 1, r);

    nodes[0][mask][id] = min(nodes[0][mask][id << 1], nodes[0][mask][id << 1 | 1]);
    nodes[1][mask][id] = max(nodes[1][mask][id << 1], nodes[1][mask][id << 1 | 1]);
}

pair<int, int> get(int mask, int u, int v, int id = 1, int l = 1, int r = n){
    if(v < l || r < u) return {INT_MAX, INT_MIN};
    if(u <= l && r <= v) return {nodes[0][mask][id], nodes[1][mask][id]};

    int mid = (l + r) >> 1;
    pair<int, int> L, R; L = R = {INT_MAX, INT_MIN};
    if(u <= mid) L = get(mask, u, v, id << 1, l, mid);
    if(mid < v) R = get(mask, u, v, id << 1 | 1, mid + 1, r);
    return {min(L.first, R.first), max(L.second, R.second)};
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            cin >> a[i][j];
        }
    }

    for(int mask = 0; mask < (1 << k); ++mask)
        build(mask);

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int i; cin >> i;
            for(int j = 0; j < k; ++j)
                cin >> a[i][j];

            for(int mask = 0; mask < (1 << k); ++mask)
                update(mask, i);
        }
        else{
            int l, r;
            cin >> l >> r;

            int ans = 0;
            for(int mask = 0; mask < (1 << k); ++mask){
                int mn, mx; tie(mn, mx) = get(mask, l, r);
                ans = max(ans, mx - mn);
            }

            cout << ans << "\n";
        }
    }

    return 0;
}
