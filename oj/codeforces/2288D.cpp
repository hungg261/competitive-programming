/******************************************************************************
Link: https://codeforces.com/contest/2288/problem/D
Code: 2288D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-21-23.12.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e14 + 5;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), pre(n + 1);
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    auto check = [&](int X) -> bool {
        int T = pre[n] - X;
        int p = lower_bound(pre.begin(), pre.end(), T) - pre.begin();
        int q = upper_bound(pre.begin(), pre.end(), X) - pre.begin();

        int sumF;
        if(p >= q) sumF = pre[n];
        else sumF = pre[p] + (pre[n] - pre[q - 1]);
        return sumF <= X;
    };

    int lo = 1, hi = INF, res = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(check(mid)){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res << "\n";
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
