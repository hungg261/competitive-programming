/******************************************************************************
Link: https://codeforces.com/problemset/problem/2152/B
Code: 2152B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-18.21.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int res = 0;
    if(x1 < x2) res = max(res, x2);
    else if(x1 > x2) res = max(res, n - x2);

    if(y1 < y2) res = max(res, y2);
    else if(y1 > y2) res = max(res, n - y2);

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
