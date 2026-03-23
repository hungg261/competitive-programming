#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    int st = 0, en = 0;
    for(int i = 1; i <= n; ++i){
        int l, r;
        cin >> l >> r;

        if(l <= k && k <= r){
            if(l == k) ++st;
            if(r == k) ++en;
        }
    }

    bool ok = (st > 0 && en > 0);
    cout << (ok ? "YES" : "NO") << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
