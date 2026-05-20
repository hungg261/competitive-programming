/******************************************************************************
Link: https://codeforces.com/contest/1006/problem/F
Code: 1006F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-20-17.09.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 20;
long long a[MAX + 5][MAX + 5], k;
int n, m;

map<long long, int> dp[MAX + 5][MAX + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    if(n == 1 && m == 1){
        cout << (a[1][1] == k ? 1 : 0) << "\n";
        return 0;
    }

    int len = min(n, m);

    dp[1][1][a[1][1]]++;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i + j - 1 < len){
                for(auto [x, _]: dp[i][j]) dp[i + 1][j][x ^ a[i + 1][j]]++;
                for(auto [x, _]: dp[i][j]) dp[i][j + 1][x ^ a[i][j + 1]]++;
            }
        }
    }

    dp[n][m][a[n][m]]++;
    for(int i = n; i >= 1; --i){
        for(int j = m; j >= 1; --j){
            if(i + j - 1 > len + 1){
                for(auto [x, _]: dp[i][j]) dp[i - 1][j][x ^ a[i - 1][j]]++;
                for(auto [x, _]: dp[i][j]) dp[i][j - 1][x ^ a[i][j - 1]]++;
            }
        }
    }

    long long res = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i + j - 1 == len){
                for(auto [x, cnt]: dp[i][j]){
                    res += 1LL * dp[i + 1][j][k ^ x] * cnt;
                    res += 1LL * dp[i][j + 1][k ^ x] * cnt;
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}
