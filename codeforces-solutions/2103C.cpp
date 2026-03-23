/******************************************************************************
Link: https://codeforces.com/contest/2103/problem/C
Code: 2103C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-09.59.05
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

        arr[i] = arr[i] <= k ? 1 : -1;
        pre[i] = pre[i - 1] + arr[i];
    }

    int l = 1, r = n;
    for(; l <= n; ++l) if(pre[l] >= 0) break;
    for(; r >= 1; --r) if(pre[n] - pre[r - 1] >= 0) break;
    if(l < r){
        cout << "YES\n";
        return;
    }

    auto check = [&](){
        vector<int> sufMax(n + 1);
        sufMax[n] = pre[n];
        for(int i = n - 1; i >= 1; --i)
            sufMax[i] = max(sufMax[i + 1], pre[i]);

        int preMin = 0;
        for(int i = 1; i < n; ++i){
            if(preMin <= pre[i] && pre[i] <= sufMax[i + 1])
                return true;
        }

        return false;
    };

    if(check()){
        cout << "YES\n";
        return;
    }

    reverse(begin(arr) + 1, end(arr));
    for(int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + arr[i];

    if(check()){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
