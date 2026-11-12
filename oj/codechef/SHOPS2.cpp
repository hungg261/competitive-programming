/******************************************************************************
Link: https://www.codechef.com/START264C/problems/SHOPS2
Code: SHOPS2
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-11-21.35.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, D;
    cin >> n >> D;

    vector<int> a(n), b(n);
    for(int &ele: a) cin >> ele;
    for(int &ele: b) cin >> ele;

    int res = D + min(
                        accumulate(begin(a), end(a), 0),
                        accumulate(begin(b), end(b), 0)
                      );
    int cur = D * 2;
    for(int i = 0; i < n; ++i){
        cur += min(a[i], b[i]);
    }

    cout << min(res, cur) << "\n";
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
