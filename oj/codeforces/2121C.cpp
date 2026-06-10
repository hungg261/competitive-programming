#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> arr[i][j];
        }
    }

    vector<int> row(n + 1, 0), col(m + 1, 0);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) row[i] = max(row[i], arr[i][j]);
    for(int j = 1; j <= m; ++j) for(int i = 1; i <= n; ++i) col[j] = max(col[j], arr[i][j]);

    vector<vector<int>> NW(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> NE(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> SW(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> SE(n + 2, vector<int>(m + 2, 0));
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) NW[i][j] = max({NW[i - 1][j], NW[i][j - 1], arr[i][j]});
    for(int i = n; i >= 1; --i) for(int j = 1; j <= m; ++j) SW[i][j] = max({SW[i + 1][j], SW[i][j - 1], arr[i][j]});
    for(int i = 1; i <= n; ++i) for(int j = m; j >= 1; --j) NE[i][j] = max({NE[i - 1][j], NE[i][j + 1], arr[i][j]});
    for(int i = n; i >= 1; --i) for(int j = m; j >= 1; --j) SE[i][j] = max({SE[i + 1][j], SE[i][j + 1], arr[i][j]});

    int ans = 1e9;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int cur = max(max({NW[i - 1][j - 1], NE[i - 1][j + 1], SW[i + 1][j - 1], SE[i + 1][j + 1]}), max(row[i], col[j]) - 1);
            ans = min(ans, cur);
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}
