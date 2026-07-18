/******************************************************************************
Link: https://oj.uz/problem/view/JOI17_foehn_phenomena
Code: JOI17_foehn_phenomena
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-18-10.12.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int N, Q, S, T;
int arr[MAXN + 5];

namespace Brute{

void solve(){
    while(Q--){
        int l, r, x;
        cin >> l >> r >> x;

        for(int i = l; i <= r; ++i) arr[i] += x;

        int res = 0;
        for(int i = 1; i <= N; ++i){
            if(arr[i - 1] < arr[i]) res -= S * (arr[i] - arr[i - 1]);
            else res += T * (arr[i - 1] - arr[i]);
        }

        cout << res << "\n";
    }
}

}

namespace Solve{

namespace ST{

const int INF = 1e18;
int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];

void build(int id = 1, int l = 0, int r = N){
    lazy[id] = 0;
    if(l == r){
        nodes[id] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
}

void apply(int id, int lz){
    nodes[id] += lz;
    lazy[id] += lz;
}

void push(int id){
    apply(id << 1, lazy[id]);
    apply(id << 1 | 1, lazy[id]);
    lazy[id] = 0;
}

void add(int u, int v, int val, int id = 1, int l = 0, int r = N){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        apply(id, val);
        return;
    }

    push(id);

    int mid = (l + r) >> 1;
    add(u, v, val, id << 1, l, mid);
    add(u, v, val, id << 1 | 1, mid + 1, r);
    nodes[id] = max(nodes[id << 1], nodes[id << 1 | 1]);
}

int get(int idx, int id = 1, int l = 0, int r = N){
    if(r < idx || idx < l) return -INF;
    if(l == r) return nodes[id];

    push(id);

    int mid = (l + r) >> 1;
    return max(get(idx, id << 1, l, mid),
               get(idx, id << 1 | 1, mid + 1, r));
}

}

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        ++idx;
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        ++idx;
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwt;
inline int f(int a, int b){ return a < b ? -S * (b - a) : T * (a - b); }

int query(int l, int r, int x){
    if(r + 1 <= N) fwt.update(r + 1, -f(ST::get(r), ST::get(r + 1)));
    fwt.update(l, -f(ST::get(l - 1), ST::get(l)));

    ST::add(l, r, x);

    if(r + 1 <= N) fwt.update(r + 1, f(ST::get(r), ST::get(r + 1)));
    fwt.update(l, f(ST::get(l - 1), ST::get(l)));

    return fwt.get(0, N);
}

void solve(){
    fwt = FenwickTree(N + 1);
    for(int i = 1; i <= N; ++i){
        fwt.update(i, f(arr[i - 1], arr[i]));
    }

    ST::build();

    while(Q--){
        int l, r, x;
        cin >> l >> r >> x;

        cout << query(l, r, x) << "\n";
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q >> S >> T;
    for(int i = 0; i <= N; ++i) cin >> arr[i];

    Solve::solve();

    return 0;
}
