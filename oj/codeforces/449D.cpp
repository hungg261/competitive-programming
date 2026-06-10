/******************************************************************************
Link: https://codeforces.com/contest/449/problem/D
Code: 449D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-25-16.20.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXVAL = 1e6, MAXLG = __lg(MAXVAL) + 1;
int n, a[MAXN + 5];
int dp[1 << MAXLG];

void solve(){
    for(int i = 0; i < MAXLG; ++i){
        for(int mask = 0; mask < (1 << MAXLG); ++mask){
            if(mask >> i & 1){
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[a[i]]++;
    }

    solve();

    return 0;
}
