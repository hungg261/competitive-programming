/******************************************************************************
Link: https://codeforces.com/contest/2203/problem/A
Code: 2203A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-21.37.22
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, d;
    cin >> n >> m >> d;

    int f = d / m + 1;
    int cnt = (n + f - 1) / f;

    cout << cnt << '\n';
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
