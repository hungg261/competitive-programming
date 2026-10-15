/******************************************************************************
Link: https://codeforces.com/contest/2276/problem/A
Code: 2276A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-14-21.39.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;

    if(a <= b) cout << "-1\n";
    else cout << min(a - b, b) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;
}
