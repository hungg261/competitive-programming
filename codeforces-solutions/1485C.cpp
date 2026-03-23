/******************************************************************************
Link: https://codeforces.com/contest/1485/problem/C
Code: 1485C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-18-21.07.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int x, y;
    cin >> x >> y;

    int res = 0;
    for(int target = 1; target * target <= x; ++target){
        res += max(0LL, min(y, x / target - 1) - target);
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
