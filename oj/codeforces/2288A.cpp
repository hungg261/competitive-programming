/******************************************************************************
Link: https://codeforces.com/contest/2288/problem/A
Code: 2288A
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-21-21.37.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int ans = 1e9;
    for(int i = 0; i <= n; ++i){
        int lo = 1, hi = n, j = -1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int dmg;
            if(mid <= i + 1){
                dmg = mid * (2 * i - mid + 3) / 2;
            }
            else{
                dmg = (i + 1) * (i + 2) / 2 + (mid - i - 1);
            }

            if(dmg >= n){
                j = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        if(j != -1){
            ans = min(ans, i + j);
        }
    }

    cout << ans << "\n";
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
