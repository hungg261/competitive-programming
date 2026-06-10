/******************************************************************************
Link: https://codeforces.com/problemset/problem/1809/B
Code: 1809B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-15-19.05.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int res = sqrtl(n);
    while(res * res > n) --res;
    while(res * res < n) ++res;

    cout << res - 1 << '\n';
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
