/******************************************************************************
Link: https://codeforces.com/contest/558/problem/E
Code: 558E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-10.14.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int nodes[26][MAXN * 4 + 5], lazy[26][MAXN * 4 + 5];
int n;

void apply(int c, int id, int l, int r, int val){
    nodes[c][id] = val * (r - l + 1);
    lazy[c][id] = val;
}

void down(int c, int id, int l, int r){
    int &lz = lazy[c][id];
    if(lz == -1) return;

    int mid = (l + r) >> 1;
    apply(c, id << 1, l, mid, lz);
    apply(c, id << 1 | 1, mid + 1, r, lz);

    lz = -1;
}

void update(int c, int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(c, id, l, r, val);
        return;
    }

    down(c, id, l, r);

    int mid = (l + r) >> 1;
    update(c, id << 1, l, mid, u, v, val);
    update(c, id << 1 | 1, mid + 1, r, u, v, val);
    nodes[c][id] = nodes[c][id << 1] + nodes[c][id << 1 | 1];
}

int get(int c, int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v){
        return nodes[c][id];
    }

    down(c, id, l, r);

    int mid = (l + r) >> 1;
    return get(c, id << 1, l, mid, u, v) + get(c, id << 1 | 1, mid + 1, r, u, v);
}

void sort_inc(int l, int r){
    int cnt[26] = {};
    for(int c = 0; c < 26; ++c){
        cnt[c] = get(c, 1, 1, n, l, r);
        update(c, 1, 1, n, l, r, 0);
    }

    int idx = l;
    for(int c = 0; c < 26; ++c){
        update(c, 1, 1, n, idx, idx + cnt[c] - 1, 1);
        idx += cnt[c];
    }
}

void sort_dec(int l, int r){
    int cnt[26] = {};
    for(int c = 0; c < 26; ++c){
        cnt[c] = get(c, 1, 1, n, l, r);
        update(c, 1, 1, n, l, r, 0);
    }

    int idx = l;
    for(int c = 25; c >= 0; --c){
        update(c, 1, 1, n, idx, idx + cnt[c] - 1, 1);
        idx += cnt[c];
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;

    string s;
    cin >> s;

    memset(lazy, -1, sizeof lazy);
    for(int i = 1; i <= n; ++i){
        update(s[i - 1] - 'a', 1, 1, n, i, i, 1);
    }

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        if(k == 1) sort_inc(l, r);
        else sort_dec(l, r);
    }

    for(int i = 1; i <= n; ++i){
        for(int c = 0; c < 26; ++c){
            if(get(c, 1, 1, n, i, i) == 1){
                cout << (char)(c + 'a');
                break;
            }
        }
    }

    return 0;
}
