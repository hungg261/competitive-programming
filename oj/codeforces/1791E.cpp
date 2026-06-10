/******************************************************************************
Link: https://codeforces.com/problemset/problem/1791/E
Code: 1791E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-22.38.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1), pre(n + 1);
    int total = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        total += llabs(arr[i]);
    }

    vector<int> sw(n + 1, 0);
    int s = 0;
    for(int i = 1; i <= n; ++i){
        sw[i] ^= s;
        if(arr[i] < 0) s ^= 1;
    }

    s = 0;
    for(int i = n; i >= 1; --i){
        sw[i] ^= s;
        if(arr[i] < 0) s ^= 1;
    }

    int res = -1e18;
    for(int i = 1; i <= n; ++i){
        res = max(res, total - llabs(arr[i]) + (sw[i] ? -1 : 1) * arr[i]);
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
