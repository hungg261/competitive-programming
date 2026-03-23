/******************************************************************************
Link: https://codeforces.com/problemset/problem/1840/D
Code: 1840D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-23.29.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    sort(begin(arr), end(arr));

    auto check = [&](int mid){
        int idx = 1;
        for(int i = 1; i <= 3 && idx <= n; ++i){
            idx = upper_bound(begin(arr) + idx, end(arr), arr[idx] + mid * 2) - begin(arr);
        }

        return idx > n;
    };

    int l = 0, r = 2e9, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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
