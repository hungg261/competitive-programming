/******************************************************************************
Link: https://codeforces.com/contest/1360/problem/G
Code: 1360G
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-11-14.14.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct MaxFlow{
    struct EdgeTo{
        int v, w, rev;
    };
    struct Edge{
        int u, v, w;
    };

    int n;
    vector<vector<EdgeTo>> adj;
    vector<Edge> edges;
    vector<int> level;
    vector<int> it;

    MaxFlow() = default;
    MaxFlow(int sz): n(sz){
        adj.resize(sz + 1);
        level.resize(sz + 1);
        it.resize(sz + 1, 0);
    }

    void addEdge(int u, int v, int w, bool directed = true){
        edges.push_back({u, v, w});
        adj[u].push_back({v, w, (int)adj[v].size()});
        adj[v].push_back({u, directed ? 0 : w, (int)adj[u].size() - 1});
    }

    bool bfs_push(int s, int t){
        fill(begin(level), end(level), -1);
        queue<int> que;

        que.push(s);
        level[s] = 0;
        while(!que.empty()){
            int u = que.front(); que.pop();
            for(const EdgeTo& e: adj[u]){
                if(e.w > 0 && level[e.v] == -1){
                    level[e.v] = level[u] + 1;
                    que.push(e.v);
                }
            }
        }

        return level[t] >= 0;
    }

    int dfs_sendFlow(int u, int t, int flow){
        if(flow == 0 || u == t){
            return flow;
        }

        for(int& i = it[u]; i < (int)adj[u].size(); ++i){
            EdgeTo& e = adj[u][i];
            if(e.w > 0 && level[u] + 1 == level[e.v]){
                int pushed = dfs_sendFlow(e.v, t, min(flow, e.w));

                if(pushed > 0){
                    e.w -= pushed;
                    adj[e.v][e.rev].w += pushed;
                    return pushed;
                }
            }
        }

        return 0;
    }

    void dfs_findCut(int u, vector<bool>& mark){
        if(mark[u]) return;
        mark[u] = true;

        for(const EdgeTo& e: adj[u]){
            if(e.w > 0) dfs_findCut(e.v, mark);
        }
    }

    vector<Edge> getMinCut(int s){
        vector<bool> mark(n + 1, false);
        dfs_findCut(s, mark);

        vector<Edge> cuts;
        for(const Edge& e: edges){
            if(mark[e.u] ^ mark[e.v]) cuts.emplace_back(e);
        }

        return cuts;
    }

    int getFlow(int s, int t){
        int res = 0;
        while(bfs_push(s, t)){
            fill(begin(it), end(it), 0);
            while(int pushed = dfs_sendFlow(s, t, INF))
                res += pushed;
        }

        return res;
    }
};

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if(n * a != m * b){
        cout << "NO\n";
        return;
    }

    MaxFlow flow(n + m + 1);
    const int S = 0, T = n + m + 1;
    for(int i = 1; i <= n; ++i) flow.addEdge(S, i, a);
    for(int j = 1; j <= m; ++j) flow.addEdge(n + j, T, b);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            flow.addEdge(i, n + j, 1);
        }
    }

    int maxFlow = flow.getFlow(S, T);

    cout << "YES\n";

    vector<vector<bool>> arr(n + 1, vector<bool>(m + 1));
    for(int i = 1; i <= n; ++i){
        for(const MaxFlow::EdgeTo& e: flow.adj[i]){
            if(n < e.v && e.v <= n + m) arr[i][e.v - n] = e.w == 0;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << arr[i][j];
        }
        cout << "\n";
    }
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
