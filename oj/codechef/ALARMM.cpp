/******************************************************************************
Link: https://www.codechef.com/START262C/problems/ALARMM
Code: ALARMM
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-28-21.33.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int res = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            ++res;
            i += k;
        }
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
