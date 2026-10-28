/******************************************************************************
Link: https://www.codechef.com/START262C/problems/COLLAPSEE
Code: COLLAPSEE
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-22.39.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    if(n == 1){
        cout << a[0] << "\n";
        return;
    }

    int ans = -a[n - 2] + a[n - 1];

    for(int i = 0; i < n - 2; ++i){
        ans += llabs(a[i]);
    }

    cout << ans << "\n";
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
