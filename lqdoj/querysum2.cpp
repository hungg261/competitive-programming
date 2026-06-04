/******************************************************************************
Link: https://lqdoj.edu.vn/problem/querysum2
Code: querysum2
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-21.46.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

FenwickTree fwt1, fwt2;

void add(int i, int x){
    fwt1.update(i, x);
    fwt2.update(i, x * i);
}

void add(int l, int r, int x){
    add(l, x);
    add(r + 1, -x);
}

int query(int i){
    return (i + 1) * fwt1.get(i) - fwt2.get(i);
}

int query(int l, int r){ return query(r) - query(l - 1); }

void solve(){
    int n, q;
    cin >> n >> q;

    fwt1 = FenwickTree(n + 1); fwt2 = FenwickTree(n + 1);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        add(i, i, cur);
    }

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int u, v, x;
            cin >> u >> v >> x;

            add(u, v, x);
        }
        else{
            int u, v;
            cin >> u >> v;

            cout << query(u, v) << "\n";
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
