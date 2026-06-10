/******************************************************************************
Link: https://codeforces.com/problemset/problem/1932/B
Code: 1932B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-20.52.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    int res = 0;
    for(int i = 1; i <= n; ++i){
        res = max(res, (res + arr[i]) / arr[i] * arr[i]);
    }

    cout << res << '\n';
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
