/******************************************************************************
Link: https://codeforces.com/problemset/problem/1689/D
Code: 1689D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-26-23.15.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    int Xmin, Xmax, Ymin, Ymax;
    Xmin = Ymin = INF; Xmax = Ymax = -INF;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(grid[i][j] == 'B'){
                int u = i + j, v = i - j;
                Xmin = min(Xmin, u);
                Xmax = max(Xmax, u);
                Ymin = min(Ymin, v);
                Ymax = max(Ymax, v);
            }
        }
    }

    pair<int, pair<int, int>> ans = {INF, {-1, -1}};
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int u = i + j, v = i - j;

            pair<int, pair<int, int>> cur = {
                max({llabs(u - Xmax), llabs(u - Xmin), llabs(v - Ymin), llabs(v - Ymax)}),
                {i, j}
            };
            ans = min(ans, cur);
        }
    }

    int x, y; tie(x, y) = ans.second;
    cout << x << " " << y << "\n";
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
