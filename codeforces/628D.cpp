/******************************************************************************
Link: https://codeforces.com/contest/628/problem/D
Code: 628D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-09-12.06.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXM = 2000, MAXLEN = 2000;
int m, d;
int numL[MAXLEN + 5], numR[MAXLEN + 5];
int dp[MAXLEN + 5][2][2][MAXM];

int Try(int idx, int smaller, int larger, int mod, int c){
    if(idx < 0) return mod == 0;

    int &memo = dp[idx][smaller][larger][mod];
    if(memo != -1) return memo;

    int st = c > 1 ? 0 : 1;
    int limL = max(st, larger ? 0 : numL[idx]);
    int limR = smaller ? 9 : numR[idx];
    memo = 0;

    if(c & 1) for(int digit = limL; digit <= limR; ++digit){
        if(digit == d) continue;
        memo = (1LL * memo + Try(idx - 1, smaller || (digit < limR), larger || (digit > limL), (mod * 10 + digit) % m, c + 1)) % MOD;
    }
    else if(limL <= d && d <= limR) memo = (1LL * memo + Try(idx - 1, smaller || (d < limR), larger || (d > limL), (mod * 10 + d) % m, c + 1)) % MOD;

    return memo;
}

int solve(string L, string R){
    int len = 0;
    while(!L.empty()){
        numL[len++] = L.back() - '0';
        L.pop_back();
    }

    len = 0;
    while(!R.empty()){
        numR[len++] = R.back() - '0';
        R.pop_back();
    }

    memset(dp, -1, sizeof dp);
    return Try(len - 1, 0, 0, 0, 1);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> d;
    string L, R;
    cin >> L >> R;

    cout << solve(L, R) << "\n";

    return 0;
}
