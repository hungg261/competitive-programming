/******************************************************************************
Link: https://codeforces.com/contest/2101/problem/B
Code: 2101B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-06-17.18.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<int>> dp(n + 1);
    dp[n] = {};
    for(int i = n - 1; i > n - 4 && i >= 0; --i){
        dp[i].push_back(a[i]);
        for(int x: dp[i + 1]) dp[i].push_back(x);
    }

    for(int i = n - 4; i >= 0; --i){
        if(a[i + 2] < a[i] || (a[i + 2] == a[i] && a[i + 3] < a[i + 1])){
            dp[i] = {a[i + 2], a[i + 3], a[i], a[i + 1]};
            for(int x: dp[i + 4]) dp[i].push_back(x);
        }
        else{
            dp[i].push_back(a[i]);
            for(int x: dp[i + 1]) dp[i].push_back(x);
        }
    }

    for(int x: dp[0]) cout << x << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
