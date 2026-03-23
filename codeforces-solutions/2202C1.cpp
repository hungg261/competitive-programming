/******************************************************************************
Link: https://codeforces.com/contest/2202/problem/C1
Code: 2202C1
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-22.41.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<int> sta;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && (sta.back() >= a[i] || sta.back() + 1 < a[i])){
            sta.pop_back();
        }

        if(sta.empty()) ++res;
        sta.push_back(a[i]);
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
