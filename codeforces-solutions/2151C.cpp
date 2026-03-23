/******************************************************************************
Link: https://codeforces.com/problemset/problem/2151/C
Code: 2151C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-22.07.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n * 2 + 2);
    for(int i = 1; i <= n * 2; ++i){
        cin >> arr[i];
    }
    arr[0] = arr[n * 2 + 1] = 0;

    vector<int> pre(n * 2 + 1);
    pre[0] = 0;
    for(int i = 1; i <= n * 2; ++i){
        pre[i] = pre[i - 1] + ((i & 1) ? -1 : 1) * arr[i];
    }

    int sided = 0;
    for(int k = 1; k <= n; ++k){
        int res = sided + ((k & 1) ? 1 : -1) * (pre[n * 2 - k + 1] - pre[k - 1]);
        sided += arr[n * 2 - k + 1] - arr[k];

        cout << res << ' ';
    }
    cout << '\n';
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
