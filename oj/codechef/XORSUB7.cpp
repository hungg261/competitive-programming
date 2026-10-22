/******************************************************************************
Link: https://www.codechef.com/problems/XORSUB7
Code: XORSUB7
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-22-20.45.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    sort(begin(a) + 1, end(a));
    vector<int> dp(n + 1);
    dp[0] = 0;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        dp[i] = 1;
        for(int j = 1; j < i; ++j){
            if((a[i] ^ a[j]) == a[i] - a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        res = max(res, dp[i]);
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
