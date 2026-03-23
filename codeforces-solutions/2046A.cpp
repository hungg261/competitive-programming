/******************************************************************************
Link: https://codeforces.com/problemset/problem/2046/A
Code: 2046A
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-14-21.18.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[j][i];
        }
    }

    int res = 0;
    for(int j = 0; j < n; ++j){
        res += max(arr[j][0], arr[j][1]);
    }

    int ans = -1e9;
    for(int j = 0; j < n; ++j){
        ans = max(ans, res - max(arr[j][0], arr[j][1]) + arr[j][0] + arr[j][1]);
    }

    cout << ans << '\n';
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
