/******************************************************************************
Link: https://csp.vnoi.info/problem/lmh_lcis#submit
Code: lmh_lcis
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-11.49.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int n, m, a[MAXN + 5], b[MAXN + 5];

int dp[MAXN + 5][MAXN + 5];
int trace[MAXN + 5][MAXN + 5];

void solve(){
    pair<int, int> ans = {0, 0};
    for(int i = 1; i <= n; ++i){
        pair<int, int> best = {0, 0};
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i - 1][j];
            trace[i][j] = trace[i - 1][j];

            if(a[i] == b[j] && best.first + 1 > dp[i][j]){
                dp[i][j] = best.first + 1;
                trace[i][j] = -best.second;
            }

            if(b[j] < a[i]) best = max(best, {dp[i - 1][j], -j});

            ans = max(ans, {dp[i][j], -j});
        }
    }

    int res = ans.first;
    cout << res << "\n";
    int best_i = n, best_j = -ans.second;

    vector<int> seq;
    while(true){
        if(best_i <= 0 || best_j <= 0) break;

        seq.push_back(b[best_j]);

        best_j = trace[best_i][best_j];
        for(; best_i >= 1 && a[best_i] != b[best_j]; --best_i){}
    }

    reverse(begin(seq), end(seq));
    for(int x: seq) cout << x << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    solve();

    return 0;
}
