/******************************************************************************
Link: https://codeforces.com/problemset/problem/1791/G1
Code: 1791G1
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-18.33.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] += i;
    }

    sort(begin(arr), end(arr));
    for(int i = 1; i <= n; ++i){
        if(m - arr[i] < 0){
            cout << i - 1 << '\n';
            return;
        }

        m -= arr[i];
    }

    cout << n << '\n';
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
