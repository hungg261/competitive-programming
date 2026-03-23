/******************************************************************************
Link: https://codeforces.com/problemset/problem/1829/E
Code: 1829E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-20.57.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1000;
int h[MAX + 5][MAX + 5], n, m;
int mark[MAX + 5][MAX + 5];

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int& res){
    if(mark[x][y] || h[x][y] == 0) return;
    mark[x][y] = true;
    res += h[x][y];

    for(int d = 0; d < 4; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !mark[nx][ny] && h[x][y] > 0){
            dfs(nx, ny, res);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> h[i][j];
            mark[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int res = 0;
            if(!mark[i][j]){
                dfs(i, j, res);
            }
            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
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
