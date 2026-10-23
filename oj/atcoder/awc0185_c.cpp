/******************************************************************************
Link: https://atcoder.jp/contests/awc0185/tasks/awc0185_c
Code: awc0185_c
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-18.04.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), P(n + 1);
    P[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        P[i] = P[i - 1] + a[i];
    }

    map<int, int> mp; mp[P[0]]++;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        res += mp[P[i] - k];
        mp[P[i]]++;
    }

    cout << res << "\n";

    return 0;
}
