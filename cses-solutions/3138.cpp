/******************************************************************************
Link: https://cses.fi/problemset/task/3138
Code: 3138
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-23-10.50.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
namespace SegmentTree{

int nodes[2][MAXN * 4 + 5], lazy[2][MAXN * 4 + 5];

void apply(int o, int id, int lz){
    nodes[o][id] = min(nodes[o][id], lz);
    lazy[o][id] = min(lazy[o][id], lz);
}

void down(int o, int id){
    int &lz = lazy[o][id];
    if(lz == INT_MAX) return;

    apply(o, id << 1, lz);
    apply(o, id << 1 | 1, lz);

    lz = INT_MAX;
}

void build(int o, int id, int l, int r){
    lazy[o][id] = INT_MAX;
    if(l == r){
        nodes[o][id] = l + 1;
        return;
    }

    int mid = (l + r) >> 1;
    build(o, id << 1, l, mid);
    build(o, id << 1 | 1, mid + 1, r);
    nodes[o][id] = min(nodes[o][id << 1], nodes[o][id << 1 | 1]);
}

void update(int o, int id, int l, int r, int u, int v, int value){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(o, id, value);
        return;
    }

    down(o, id);

    int mid = (l + r) >> 1;
    update(o, id << 1, l, mid, u, v, value);
    update(o, id << 1 | 1, mid + 1, r, u, v, value);
    nodes[o][id] = min(nodes[o][id << 1], nodes[o][id << 1 | 1]);
}

int get(int o, int id, int l, int r, int idx){
    if(l == r) return nodes[o][id];

    down(o, id);

    int mid = (l + r) >> 1;
    if(idx <= mid) return get(o, id << 1, l, mid, idx);
    else return get(o, id << 1 | 1, mid + 1, r, idx);
}

}
using namespace SegmentTree;

string s;
int n;

const int BASE = 31, MOD = 1e9 + 23;
int hashes[MAXN + 5], rev_hashes[MAXN + 5], powhash[MAXN + 5];
string rev_s;

void compute(){
    powhash[0] = 1 % MOD;
    for(int i = 1; i <= n; ++i){
        powhash[i] = powhash[i - 1] * BASE % MOD;
        hashes[i] = (hashes[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
        rev_hashes[i] = (rev_hashes[i - 1] * BASE + rev_s[i] - 'a' + 1) % MOD;
    }
}

int getHash(int l, int r){
    return ((hashes[r] - hashes[l - 1] * powhash[r - l + 1]) % MOD + MOD) % MOD;
}

int getRevHash(int l, int r){
    return ((rev_hashes[r] - rev_hashes[l - 1] * powhash[r - l + 1]) % MOD + MOD) % MOD;
}

bool check_palindrome(int l, int r){
    return getHash(l, r) == getRevHash(n - r + 1, n - l + 1);
}

int cnp_chan(int center){
    int l = 1, r = min(center - 1, n - center + 1), res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check_palindrome(center - mid, center + mid - 1)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

int cnp_le(int center){
    int l = 1, r = min(center, n - center + 1), res = 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check_palindrome(center - mid + 1, center + mid - 1)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void solve(){
    rev_s = s;
    reverse(begin(rev_s), end(rev_s));

    s = '^' + s; rev_s = '^' + rev_s;

    compute();

    for(int i = 1; i <= n; ++i){
        int e = cnp_chan(i), o = cnp_le(i);

        update(0, 1, 1, n, i, i + e - 1, i);
        update(1, 1, 1, n, i, i + o - 1, i);
    }

    for(int i = 1; i <= n; ++i){
        int e = get(0, 1, 1, n, i), o = get(1, 1, 1, n, i);
        int len_e = 2 * (i - e + 1), len_o = 2 * (i - o + 1) - 1;

        cout << max(len_e, len_o) << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.size();

    build(0, 1, 1, n);
    build(1, 1, 1, n);

    solve();

    return 0;
}
