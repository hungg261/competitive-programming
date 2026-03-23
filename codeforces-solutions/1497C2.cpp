/******************************************************************************
Link: https://codeforces.com/contest/1497/problem/C2
Code: 1497C2
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-23.51.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k - 3; ++i, --n) cout << 1 << ' ';


    if(n % 2 == 1){
        cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
    }
    else if(n % 4 == 0){
        cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
    }
    else{
        cout << 2 << ' ' << n / 2 - 1 << ' ' << n / 2 - 1 << '\n';
    }
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
