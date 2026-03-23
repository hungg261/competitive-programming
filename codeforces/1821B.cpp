/******************************************************************************
Link: https://codeforces.com/contest/1821/problem/B
Code: 1821B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-12-22.40.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    int l = 1, r = n;
    while(l <= n && a[l] == b[l]) ++l;
    while(r >= 1 && a[r] == b[r]) --r;

    while(l > 1 && b[l - 1] <= b[l]) --l;
    while(r < n && b[r] <= b[r + 1]) ++r;

    cout << l << ' ' << r << '\n';
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
