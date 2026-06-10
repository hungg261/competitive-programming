/******************************************************************************
Link: https://codeforces.com/problemset/problem/1899/B
Code: 1899B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-20.25.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> pref(n + 1);
    pref[0] = 0;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        pref[i] = pref[i - 1] + cur;
    }

    int res = 0;
    for(int k = 1; k <= n; ++k){
        if(n % k != 0) continue;

        int maxVal = -1e18;
        int minVal = 1e18;
        for(int i = k; i <= n; i += k){
            int sum = pref[i] - pref[i - k];
            maxVal = max(maxVal, sum);
            minVal = min(minVal, sum);
        }

        res = max(res, maxVal - minVal);
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
