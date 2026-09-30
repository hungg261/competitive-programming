/******************************************************************************
Link: https://www.codechef.com/START258D/problems/CHOCCUT
Code: CHOCCUT
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-21.40.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    cout << ((n % 2 == 0 || m % 2 == 0) ? "Yes" : "No") << "\n";
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
