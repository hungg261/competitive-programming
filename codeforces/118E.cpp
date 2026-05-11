/******************************************************************************
Link: https://codeforces.com/contest/118/problem/E
Code: 118E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-11-10.48.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m;
vector<int> adj[MAXN + 5];

vector<pair<int, int>> res;
int tin[MAXN + 5], low[MAXN + 5], Timer = 0;

void dfs(int u, int prv){
    tin[u] = low[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;

        if(tin[v]){
            low[u] = min(low[u], tin[v]);
            if(tin[u] > tin[v]){
                res.emplace_back(u, v);
            }
        }
        else{
            res.emplace_back(u, v);

            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u]){
                cout << "0\n";
                exit(0);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for(const pair<int, int>& p: res){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
