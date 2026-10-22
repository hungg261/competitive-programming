/******************************************************************************
Link: https://www.codechef.com/START261D/problems/EXPHOTO
Code: EXPHOTO
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-22.54.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int ceiling(int a, int b){ return (a + b - 1) / b; }

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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    if(k == 1){
        bool ok = is_sorted(begin(a) + 1, end(a), greater<int>());
        cout << (ok ? 0 : -1) << "\n";
        return;
    }

    FenwickTree fwt(n + 1);
    auto add = [&fwt](int l, int r, int x){
        fwt.update(r + 1, -x);
        fwt.update(l, x);
    };

    vector<int> pos(n + 1);
    for(int i = 1; i <= n; ++i){
        pos[a[i]] = i;
        add(i, i, i);
    }

    int res = 0;
    for(int v = n; v >= 1; --v){
        int idx = fwt.get(pos[v]);
        res += ceiling(idx - 1, k - 1);
        add(pos[v], n, -1);
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
