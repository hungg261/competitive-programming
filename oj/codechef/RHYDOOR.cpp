/******************************************************************************
Link: https://www.codechef.com/START262C/problems/RHYDOOR
Code: RHYDOOR
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-21.30.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cur = 1, res = 0;
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i - 1] && cur < 3){
            ++cur;
        }
        else{
            if(cur >= 3) ++res;
            cur = 1;
        }
    }
    if(cur >= 3) ++res;

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
