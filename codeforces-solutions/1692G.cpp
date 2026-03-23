/******************************************************************************
Link: https://codeforces.com/problemset/problem/1692/G
Code: 1692G
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-20-21.21.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1), pre(n + 1);
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];

        if(i > 1 && arr[i - 1] < 2 * arr[i]){
            ++pre[i - 1];
        }
        pre[i] = pre[i - 1];
    }

    int res = 0;
    for(int i = 1; i <= n - k; ++i){
        if(pre[i + k - 1] - pre[i - 1] == k) ++res;
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
