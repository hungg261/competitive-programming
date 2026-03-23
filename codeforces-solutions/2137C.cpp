/******************************************************************************
Link: https://codeforces.com/problemset/problem/2137/C
Code: 2137C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-08-12.36.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int a, b;
    cin >> a >> b;

    int cnta = 0, cntb = 0;
    while(a % 2 == 0) a /= 2, ++cnta;
    while(b % 2 == 0) b /= 2, ++cntb;

    if(cnta == 0 && cntb == 0){
        cout << (a * b + 1) << '\n';
        return;
    }
    if(cntb == 0 || (cnta == 0 && cntb == 1)){
        cout << "-1\n";
        return;
    }

    int res = ((a * b) << (cnta + cntb - 1)) + 2;
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
