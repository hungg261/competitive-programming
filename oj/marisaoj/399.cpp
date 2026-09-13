/******************************************************************************
Link: https://marisaoj.com/problem/399
Code: 399
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-13-23.16.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
string S;
int n;

long long dp[2][MAXN + 5];
int cnt0[MAXN + 5];
int cnt1[MAXN + 5][MAXN + 5];
bool is_palin[MAXN + 5][MAXN + 5];

void compute(){
    for(int i = 1; i <= n; ++i){
        is_palin[i][i - 1] = 1;
        is_palin[i][i] = 1;
    }
    for(int len = 2; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if(S[i] == S[j]){
                is_palin[i][j] |= is_palin[i + 1][j - 1];
            }
        }
    }
}

void solve(){
    compute();
    long long res = 0;

    for(int i = n; i >= 1; --i){
        if(i < n) {
            int idx = i + 1;

            cnt0[idx] = is_palin[idx][idx];
            for(int j = idx + 1; j <= n; ++j){
                cnt0[j] = cnt0[j - 1];
                if(is_palin[idx][j]) ++cnt0[j];
            }

            cnt1[idx][idx] = is_palin[idx][idx];
            for(int j = idx - 1; j >= 1; --j){
                cnt1[j][idx] = cnt1[j + 1][idx];
                if(is_palin[j][idx]) ++cnt1[j][idx];
            }
        }

        for(int j = i + 1; j <= n; ++j){
            if(S[i] == S[j]){
                dp[i & 1][j] = dp[i + 1 & 1][j - 1] + cnt0[j - 1] + cnt1[i + 1][j - 1] + 1; // -1 + 2
                res += dp[i & 1][j];
            }
            else dp[i & 1][j] = 0;
        }
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> S;
    n = S.size();
    S = "#" + S;

    solve();

    return 0;
}
