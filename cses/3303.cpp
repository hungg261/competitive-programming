/******************************************************************************
Link: https://cses.fi/problemset/task/3303
Code: 3303
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-09-20.23.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, m, k;
vector<int> adj[MAXN + 5];

queue<tuple<int, int, int>> que;
vector<pair<int, int>> dist[MAXN + 5];
void bfs(){
    while(!que.empty()){
        int d, u, root;
        tie(d, u, root) = que.front();
        que.pop();

        for(int v: adj[u]){
            for(const pair<int, int>& p: dist[v])
                if(p.second == root) goto reached;

            if((int)dist[v].size() < 2){
                dist[v].push_back({d + 1, root});
                que.push({d + 1, v, root});
            }

            reached:;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    for(int i = 1; i <= k; ++i){
        int cur; cin >> cur;
        que.push({0, cur, cur});
    }

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    for(int u = 1; u <= n; ++u){
        int res = -1;
        for(const pair<int, int>& p: dist[u]){
            if(p.second != u){
                res = p.first;
                break;
            }
        }

        cout << res << " ";
    }
    cout << "\n";

    return 0;
}
