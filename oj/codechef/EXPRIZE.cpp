/******************************************************************************
Link: https://www.codechef.com/START261D/problems/EXPRIZE
Code: EXPRIZE
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-22.18.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int S;
    cin >> S;

    auto check = [&S](int len){
        return (len * len * len + len * 5) / 6 <= S;
    };

    int lo = 1, hi = 1817120, res = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(check(mid)){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << res << "\n";
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
