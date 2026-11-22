/******************************************************************************
Link: https://codeforces.com/contest/2288/problem/B2
Code: 2288B2
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-21-22.42.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string spell = "";
    for(int _ = 0; _ < 100; ++_) spell += "+--";

    cout << spell << endl;

    int k;
    cin >> k;

    if(k == -1) exit(0);

    cout << n + (k + 2) / 3 << "\n";
}

signed main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
