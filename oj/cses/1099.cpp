/******************************************************************************
Link: https://cses.fi/problemset/task/1099
Code: 1099
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-27-22.09.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int G = 0;
    for(int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;

        if(i % 2 == 0) G ^= cur;
    }

    cout << (G ? "first" : "second") << "\n";
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
