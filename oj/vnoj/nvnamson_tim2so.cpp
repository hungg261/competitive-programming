/******************************************************************************
Link: https://codeforces.com/group/py59YCge5m/contest/637051/problem/A
Code: A
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-26-19.02.04
*******************************************************************************/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

inline void solve(long long a, long long b){
    cout << a / b * b << ' ' << (a + b - 1) / b * b << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    int t;
    cin >> t;

    while(t--){
        long long a, b;
        cin >> a >> b;

        solve(a, b);
    }

    return 0;
}
