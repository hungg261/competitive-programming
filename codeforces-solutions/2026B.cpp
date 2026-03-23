/******************************************************************************
Link: https://codeforces.com/problemset/problem/2026/B
Code: 2026B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-17.09.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    auto check = [&](int mid){
        bool gap = false;
        int i = 0;
        for(; i < n - 1; ++i){
            if(arr[i + 1] - arr[i] <= mid){
                ++i;
            }
            else{
                if(gap) return false;
                gap = true;
            }
        }

        if(i == n) return true;
        return !gap;
    };

    int l = 1, r = 1e18, res = -1;
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
