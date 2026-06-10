/******************************************************************************
Link: https://codeforces.com/contest/1006/problem/F
Code: 1006F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-20-17.09.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 20;
long long a[MAX + 5][MAX + 5], k;
int n, m, half;
long long res = 0;

map<long long, int> dp[MAX + 1][MAX + 1];

void dfs1(int i, int j, int steps, long long cur){
    if(i > n || j > m) return;

    cur ^= a[i][j];

    if(steps == half){
        dp[i][j][cur]++;
        return;
    }

    dfs1(i + 1, j, steps + 1, cur);
    dfs1(i, j + 1, steps + 1, cur);
}

void dfs2(int i, int j, int steps, long long cur){
    if(i <= 0 || j <= 0) return;

    if(steps == (n + m - 2) - half){
        if(dp[i][j].count(k ^ cur)) res += dp[i][j][k ^ cur];
        return;
    }

    cur ^= a[i][j];
    dfs2(i - 1, j, steps + 1, cur);
    dfs2(i, j - 1, steps + 1, cur);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    half = (n + m - 2) / 2;
    dfs1(1, 1, 0, 0);
    dfs2(n, m, 0, 0);

    cout << res << "\n";

    return 0;
}
