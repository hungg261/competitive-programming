/******************************************************************************
Link: https://codeforces.com/contest/1971/problem/F
Code: 1971F
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-11.51.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int r;
    cin >> r;

    int y = r;
    int res = 0;
    for(int x = 0; x <= r; ++x){
        while(x * x + y * y >= (r + 1) * (r + 1)) --y;

        for(int h = y; h > 0 && r * r <= x * x + h * h; --h){
            ++res;
        }
    }

    cout << res * 4 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
