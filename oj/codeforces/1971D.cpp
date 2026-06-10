/******************************************************************************
Link: https://codeforces.com/contest/1971/problem/D
Code: 1971D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-12.59.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    int cnt01 = false;
    int res = 0;
    for(int i = 1; i < n; ++i){
        if(s[i - 1] == '0' && s[i] == '1') ++cnt01;
        if(s[i - 1] == '1' && s[i] == '0') ++res;
    }

    cout << res + max(0, cnt01 - 1) + 1 << '\n';
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
