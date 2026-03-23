/******************************************************************************
Link: https://codeforces.com/problemset/problem/1996/D
Code: 1996D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-17.53.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, x;
    cin >> n >> x;

    int res = 0;
    for(int a = 1; a <= x; ++a){
        for(int b = 1; b <= n / a; ++b){
            res += max(0LL, min((n - a * b) / (a + b), x - a - b));
        }
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
