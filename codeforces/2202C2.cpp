/******************************************************************************
Link: https://codeforces.com/contest/2202/problem/C2
Code: 2202C2
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-23.55.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

// unf
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

    vector<int> idx;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && (sta.back() >= a[i] || sta.back() + 1 < a[i])){
            sta.pop_back();
        }

        if(sta.empty()){
            idx.push_back(i);
        }

        if(sta.empty()) ++res;
        sta.push_back(a[i]);
    }

    for(int i = 1; i < res; ++i){
        cerr << idx[i - 1] << ' ' << idx[i] - 1 << '\n';
    }
    cout << idx.back() << ' ' << n << '\n';

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
