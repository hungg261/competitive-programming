/******************************************************************************
Link: https://cses.fi/problemset/task/3360
Code: 3360
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-09.56.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
int n, k;
vector<int> adj[26][MAXN + 5];
bool vis[MAXN + 5][MAXN + 5];

bool check(int ch){
    auto& G = adj[ch];

    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; ++i){
        for(int a: G[i]){
            for(int b: G[i]){
                if(a == b) continue;

                if(vis[a][b]) return true;
                vis[a][b] = true;
            }
        }
    }

    return false;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c;
            cin >> c;

            int ch = c - 'A';
            adj[ch][i].push_back(j);
        }
    }

    for(int ch = 0; ch < k; ++ch){
        cout << (check(ch) ? "YES" : "NO") << '\n';
    }

    return 0;
}
