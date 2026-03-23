#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        ans += abs(cur);
    }
    cout << ans << '\n';
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
