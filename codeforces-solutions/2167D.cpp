#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int ans = 69;
    for(int i = 0; i < n; ++i){
        int cur;
        cin >> cur;

        for(int j = 2; j <= 60; ++j){
            if(__gcd(j, cur) == 1){
                ans = min(ans, j);
                break;
            }
        }
    }

    if(ans != 69) cout << ans << '\n';
    else cout << "-1\n";
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
