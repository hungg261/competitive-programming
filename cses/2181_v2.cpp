/******************************************************************************
Link: https://cses.fi/problemset/task/2181
Code: 2181
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-30-18.34.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 10, MAXM = 1000;
const int MOD = 1e9 + 7;
int n, m;
int solve(int i, int mask);

int dp[MAXM][1 << MAXN];
int gen(int i, int j, int mask, int nxt_mask){
    if(i >= m) return mask == 0;
    if(j >= n) return solve(i + 1, nxt_mask) % MOD;

    if(mask >> j & 1){
        return gen(i, j + 1, mask, nxt_mask) % MOD;
    }

    int res = gen(i, j + 1, mask, nxt_mask | (1 << j)) % MOD;
    if(j + 1 < n && ~mask >> (j + 1) & 1){
        res += gen(i, j + 2, mask, nxt_mask);
        res %= MOD;
    }

    return res;
}

int solve(int i, int mask){
    if(i >= m) return mask == 0;

    int &memo = dp[i][mask];
    if(memo != -1) return memo;

    return memo = gen(i, 0, mask, 0) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) << "\n";

    return 0;
}
