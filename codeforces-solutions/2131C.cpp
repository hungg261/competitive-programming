/******************************************************************************
Link: https://codeforces.com/problemset/problem/2131/C
Code: 2131C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-17.00.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> S(n), T(n);
    for(int i = 0; i < n; ++i) cin >> S[i];
    for(int i = 0; i < n; ++i) cin >> T[i];

    map<int, int> mp;
    for(int ele: S){
        mp[ele % k]++;
    }

    for(int ele: T){
        if(mp[ele % k] > 0){
            --mp[ele % k];
            continue;
        }
        if(mp[k - ele % k] > 0){
            --mp[k - ele % k];
            continue;
        }

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
