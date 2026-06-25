/******************************************************************************
Link: https://oj.uz/problem/view/BOI16_bosses
Code: BOI16_bosses
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-25-09.38.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
vector<int> adj[MAXN + 5];
int n;

vector<int> tree[MAXN + 5];

pair<int, int> dfs(int u){
    pair<int, int> res = {0, 1};
    for(int v: tree[u]){
        int subsum, subsz;
        tie(subsum, subsz) = dfs(v);

        res.first += subsum;
        res.second += subsz;
    }

    res.first += res.second;
    return res;
}

int bfs(int st){
    queue<int> que;
    que.push(st);

    vector<int> vis(n + 1, false);
    vis[st] = true;
    int visCnt = 1;

    for(int u = 1; u <= n; ++u) tree[u].clear();
    while(!que.empty()){
        int u = que.front(); que.pop();

        for(int v: adj[u]){
            if(!vis[v]){
                tree[u].push_back(v);
                que.push(v);
                vis[v] = true; ++visCnt;
            }
        }
    }

    return visCnt == n ? dfs(st).first : INT_MAX;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u){
        int k; cin >> k;
        while(k--){
            int v; cin >> v;
            adj[v].push_back(u);
        }
    }

    int res = INT_MAX;
    for(int u = 1; u <= n; ++u)
        res = min(res, bfs(u));

    cout << res << "\n";

    return 0;
}
