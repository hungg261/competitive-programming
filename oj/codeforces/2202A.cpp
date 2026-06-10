/******************************************************************************
Link: https://codeforces.com/contest/2202/problem/A
Code: 2202A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-21.38.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x, y;
    cin >> x >> y;

    if(y >= 0 && 2 * y <= x && (x - 2 * y) % 3 == 0){
        cout << "YES\n";
        return;
    }

    if(y < 0 && 4 * -y <= x && (x - 4 * -y) % 3 == 0){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
