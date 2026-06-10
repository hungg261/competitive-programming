/******************************************************************************
Link: https://codeforces.com/contest/2025/problem/D
Code: 2025D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-25-19.22.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6, MAXM = 5000;
int n, m;
int r[MAXN + 5];

int dp[MAXM + 5];
int diff[MAXM + 5];
void solve(){
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;

    int cnt = 0;
    for(int i = 1; i <= n + 1; ++i){
        if(r[i] == 0){
            int psum = 0;
            for(int j = 0; j <= m; ++j){
                psum += diff[j];
                diff[j] = 0;

                dp[j] += psum;
            }

            for(int j = m; j >= 1; --j){
                dp[j] = max(dp[j], dp[j - 1]);
            }

            ++cnt;
        }
        else if(r[i] > 0){
            if(r[i] > m) continue;

            diff[r[i]]++;
            diff[m + 1]--;
        }
        else{
            if(0 > cnt + r[i]) continue;

            diff[0]++;
            diff[cnt + r[i] + 1]--;
        }
    }

    cout << *max_element(dp + 1, dp + m + 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> r[i];
    }

    solve();

    return 0;
}
