/******************************************************************************
Link: https://codeforces.com/contest/2214/problem/D
Code: 2214D
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-01-22.09.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    if (n == 1) cout << "walk";
    else if (n == 2) cout << "no";
    else if (n == 3) cout << "no";
    else if (n == 4) cout << "no";
    else if (n == 5) cout << "yes";
    else if (n == 6) cout << "yes";
    else if (n == 7) cout << "backwards";
    else cout << "7";
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
