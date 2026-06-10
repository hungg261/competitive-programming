/******************************************************************************
Link: https://oj.vnoi.info/problem/segtree_itmix
Code: segtree_itmix
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-21-11.00.50
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
const int MOD = 1e9 + 7;
int arr[MAXN + 5], n, q;
int nodes[MAXN * 4 + 5], lazyInc[MAXN * 4 + 5], lazySet[MAXN * 4 + 5], lazyMul[MAXN * 4 + 5];
bool isSet[MAXN * 4 + 5];

void build(int id, int l, int r){
    lazySet[id] = 0;
    lazyInc[id] = 0;
    lazyMul[id] = 1;
    isSet[id] = false;

    if(l == r){
        nodes[id] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    nodes[id] %= MOD;
}

void applySet(int id, int l, int r, int lz){
    nodes[id] = (r - l + 1) * lz;

    lazySet[id] = lz;
    lazyMul[id] = 1;
    lazyInc[id] = 0;
    isSet[id] = true;

    nodes[id] %= MOD;
}

void applyMul(int id, int l, int r, int lz){
    nodes[id] *= lz;

    if(isSet[id])
        lazySet[id] *= lz;
    else lazyMul[id] *= lz, lazyInc[id] *= lz;

    nodes[id] %= MOD;
    lazySet[id] %= MOD;
    lazyMul[id] %= MOD;
    lazyInc[id] %= MOD;
}

void applyInc(int id, int l, int r, int lz){
    nodes[id] += (r - l + 1) * lz % MOD;

    if(isSet[id])
        lazySet[id] += lz;
    else lazyInc[id] += lz;

    nodes[id] %= MOD;
    lazyInc[id] %= MOD;
    lazySet[id] %= MOD;
}

void down(int id, int l, int r){
    int mid = (l + r) >> 1;

    if(isSet[id]){
        applySet(id << 1, l, mid, lazySet[id]);
        applySet(id << 1 | 1, mid + 1, r, lazySet[id]);
        lazySet[id] = 0;
        isSet[id] = false;
    }

    if(lazyMul[id] != 1){
        applyMul(id << 1, l, mid, lazyMul[id]);
        applyMul(id << 1 | 1, mid + 1, r, lazyMul[id]);
        lazyMul[id] = 1;
    }

    if(lazyInc[id] != 0){
        applyInc(id << 1, l, mid, lazyInc[id]);
        applyInc(id << 1 | 1, mid + 1, r, lazyInc[id]);
        lazyInc[id] = 0;
    }
}

void Increase(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        applyInc(id, l, r, x % MOD);
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Increase(id << 1, l, mid, u, v, x);
    Increase(id << 1 | 1, mid + 1, r, u, v, x);

    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    nodes[id] %= MOD;
}

void Multiply(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        applyMul(id, l, r, x % MOD);
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Multiply(id << 1, l, mid, u, v, x);
    Multiply(id << 1 | 1, mid + 1, r, u, v, x);

    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    nodes[id] %= MOD;
}

void Assign(int id, int l, int r, int u, int v, int x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        applySet(id, l, r, x % MOD);
        return;
    }

    down(id, l, r);

    int mid = (l + r) >> 1;
    Assign(id << 1, l, mid, u, v, x);
    Assign(id << 1 | 1, mid + 1, r, u, v, x);

    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
    nodes[id] %= MOD;
}

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return nodes[id];

    down(id, l, r);

    int mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    build(1, 1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r, x; cin >> l >> r >> x;

            Increase(1, 1, n, l, r, x);
        }
        else if(type == 2){
            int l, r, x; cin >> l >> r >> x;

            Multiply(1, 1, n, l, r, x);
        }
        else if(type == 3){
            int l, r, x; cin >> l >> r >> x;

            Assign(1, 1, n, l, r, x);
        }
        else if(type == 4){
            int l, r; cin >> l >> r;

            cout << get(1, 1, n, l, r) % MOD << '\n';
        }
    }

    return 0;
}
