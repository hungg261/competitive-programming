/******************************************************************************
Link: https://codeforces.com/contest/2290/problem/A
Code: 2290A
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-12-21.35.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if(a[0] + 2 == a[2] && a[0] + 1 == a[1]) cout << "YES\n";
    else cout << "NO\n";
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
