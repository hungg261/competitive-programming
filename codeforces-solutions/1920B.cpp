/******************************************************************************
Link: https://codeforces.com/problemset/problem/1920/B
Code: 1920B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-17.17.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    sort(begin(arr), end(arr));
    vector<int> pre(n + 2);
    pre[0] = 0;
    for(int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + arr[i];
    pre[n + 1] = pre[n];

    int res = -1e18;
    for(int i = n; i >= n - k; --i){
        res = max(res, pre[max(0LL, i - x)] * 2 - pre[i]);
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
