/******************************************************************************
Link: https://codeforces.com/group/2W1wfqmLNZ/contest/675179/problem/B
Code: Group_2W1wfqmLNZ_675179B
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-13-14.01.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, arr[MAXN + 5][2];
int dp[MAXN + 5][6];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CHONCAM.INP","r",stdin);
    freopen("CHONCAM.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 1; i <= n; ++i){
        dp[i][arr[i][0]] = dp[i - 1][arr[i][0]] + 1;
        dp[i][arr[i][1]] = dp[i - 1][arr[i][1]] + 1;
    }

    pair<int, int> res = {-1, INT_MAX};
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 5; ++j){
            res = max(res, make_pair(dp[i][j], -j));
        }
    }

    cout << res.first << ' ' << -res.second << '\n';

    return 0;
}
