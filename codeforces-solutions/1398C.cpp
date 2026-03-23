/******************************************************************************
Link: https://codeforces.com/contest/1398/problem/C
Code: 1398C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-21-15.26.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string S;
    cin >> S;

    S = " " + S;

    map<int, int> mp;
    mp[0]++;

    int prefix = 0;
    long long res = 0;
    for(int i = 1; i <= n; ++i){
        prefix += S[i] - '0';

        res += mp[prefix - i]++;
    }

    cout << res << '\n';
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
