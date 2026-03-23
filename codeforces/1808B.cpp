/******************************************************************************
Link: https://codeforces.com/problemset/problem/1808/B
Code: 1808B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-18.42.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int cur;
            cin >> cur;

            arr[j].push_back(cur);
        }
    }

    int ans = 0;
    for(int j = 0; j < m; ++j){
        sort(begin(arr[j]), end(arr[j]));
        int res = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            res += arr[j][i] * i - sum;
            sum += arr[j][i];
        }

        ans += res;
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
