/******************************************************************************
Link: https://codeforces.com/contest/687/problem/C
Code: 687C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-11-13.27.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500, MAXK = 500, MAXSUM = MAXN * MAXK;
bitset<MAXK + 5> dp[MAXK + 5];
int n, k;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    dp[0][0] = true;

    for(int i = 1; i <= n; ++i){
        int a; cin >> a;

        for(int j = k; j >= a; --j){
            dp[j] |= dp[j - a] | (dp[j - a] << a);
        }
    }

    cout << dp[k].count() << "\n";
    for(int j = 0; j <= k; ++j){
        if(dp[k][j]) cout << j << " ";
    }

    return 0;
}
