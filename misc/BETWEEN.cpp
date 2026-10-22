/******************************************************************************
Link: https://www.codechef.com/START261D/problems/BETWEEN
Code: BETWEEN
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-21.35.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int X, Y;
    cin >> X >> Y;

    if(X > Y) swap(X, Y);

    cout << Y - X - 1 << endl;
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
