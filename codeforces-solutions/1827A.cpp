/******************************************************************************
Link: https://codeforces.com/problemset/problem/1827/A
Code: 1827A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-20.58.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    sort(begin(a) + 1, end(a));
    sort(begin(b) + 1, end(b));

    int res = 1;
    for(int i = 1; i <= n; ++i){
        res = res * ((n - (upper_bound(begin(a) + 1, end(a), b[i]) - begin(a)) + 1) - (n - i)) % MOD;
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
