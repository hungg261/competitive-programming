/******************************************************************************
Link: https://codeforces.com/contest/2283/problem/A
Code: 2283A
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-21.47.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;

    if(l <= 0 && r >= 0){
        int mn = min(-l, r);
        cout << max(0, max(-mn - l, r - mn) - 1) << "\n";
    }
    else{
        cout << (r - l) << "\n";
    }
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
