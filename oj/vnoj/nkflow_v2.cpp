/******************************************************************************
Link: https://oj.vnoi.info/problem/nkflow
Code: nkflow
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-17-15.09.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct MaxFlow{
    struct EdgeTo{
        int v, w, rev;
    };

    int n;
    vector<vector<EdgeTo>> adj;
    vector<int> it, level;

    MaxFlow(int _n): n(_n){
        adj.resize(n + 1);
        it.resize(n + 1);
        level.resize(n + 1);
    }

    void add_edge(int u, int v, int w, bool directed = true){
        adj[u].push_back({v, w, (int)adj[v].size()});
        adj[v].push_back({u, (directed ? 0 : w), (int)adj[u].size() - 1});
    }

    bool bfs(int s, int t){
        fill(begin(level), end(level), -1);
        queue<int> que;
        que.push(s);
        level[s] = 0;

        while(!que.empty()){
            int u = que.front(); que.pop();
            for(const EdgeTo& e: adj[u]){
                if(e.w > 0 && level[e.v] == -1){
                    que.push(e.v);
                    level[e.v] = level[u] + 1;
                }
            }
        }

        return level[t] >= 0;
    }

    int dfs(int u, int flow, int t){
        if(flow == 0 || u == t) return flow;

        for(int &i = it[u]; i < (int)adj[u].size(); ++i){
            EdgeTo& e = adj[u][i];
            if(e.w > 0 && level[u] + 1 == level[e.v]){
                int pushed = dfs(e.v, min(flow, e.w), t);
                if(pushed > 0){
                    e.w -= pushed;
                    adj[e.v][e.rev].w += pushed;
                    return pushed;
                }
            }
        }

        return 0;
    }

    int getFlow(int s, int t){
        int res = 0;
        while(bfs(s, t)){
            fill(begin(it), end(it), 0);
            while(int pushed = dfs(s, INT_MAX, t)){
                res += pushed;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    MaxFlow flow(n);
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        flow.add_edge(a, b, c);
    }

    cout << flow.getFlow(s, t) << "\n";

    return 0;
}
