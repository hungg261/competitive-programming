/******************************************************************************
Link: https://www.codechef.com/START264C/problems/ROT4
Code: ROT4
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-11-21.38.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    n = s.size();
    s += s[0];

    int res = 0;
    for(int i = 0; i < n; ++i){
        if(stoi(s.substr(i, 2)) % 4 == 0) ++res;
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
