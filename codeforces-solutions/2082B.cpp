/******************************************************************************
Link: https://codeforces.com/contest/2082/problem/B
Code: 2082B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-10-16.50.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x, n, m;
    cin >> x >> n >> m;

    n = min(n, 31);
    m = min(m, 31);
    vector<vector<int>> dpMin(n + 1, vector<int>(m + 1));
    vector<vector<int>> dpMax(n + 1, vector<int>(m + 1));

    dpMin[0][0] = dpMax[0][0] = x;
    for(int i = 1; i <= n; ++i) dpMin[i][0] = dpMax[i][0] = dpMin[i - 1][0] / 2;
    for(int j = 1; j <= m; ++j) dpMin[0][j] = dpMax[0][j] = (dpMin[0][j - 1] + 1) / 2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dpMin[i][j] = min(dpMin[i - 1][j] / 2, (dpMin[i][j - 1] + 1) / 2);
            dpMax[i][j] = max(dpMax[i - 1][j] / 2, (dpMax[i][j - 1] + 1) / 2);
        }
    }

    cout << dpMin[n][m] << ' ' << dpMax[n][m] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
