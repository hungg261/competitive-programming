/******************************************************************************
Link: https://codeforces.com/contest/2284/problem/A2
Code: 2284A2
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-06-21.41.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = 1LL << a[i];
    }

    sort(begin(a), end(a), greater<int>());

    int sum[2] = {};
    for(int i = 0; i < n; ++i){
        int b = sum[0] < sum[1] ? 0 : 1;
        sum[b] += a[i];
    }

    cout << sum[0] * sum[1] << "\n";
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
