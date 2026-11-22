/******************************************************************************
Link: https://atcoder.jp/contests/abc259/tasks/abc259_g
Code: abc259_g
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-22-10.15.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

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
        fill(begin(level) + 1, end(level), -1);
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
            fill(begin(it) + 1, end(it), 0);
            while(int pushed = dfs_sendFlow(s, t, INF))
                res += pushed;
        }

        return res;
    }
};

const int MAX = 100;
int n, m, a[MAX + 5][MAX + 5];

void solve(){
    const int S = n + m + 1, T = S + 1;
    MaxFlow flow(T);

    auto row = [](int i){ return i; };
    auto col = [](int j){ return n + j; };

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int sum = 0;
        for(int j = 1; j <= m; ++j){
            sum += a[i][j];
        }

        if(sum >= 0){
            flow.addEdge(S, row(i), sum);
            ans += sum;
        }
        else flow.addEdge(row(i), T, -sum);
    }

    for(int j = 1; j <= m; ++j){
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += a[i][j];
        }

        if(sum >= 0){
            flow.addEdge(col(j), T, sum);
            ans += sum;
        }
        else flow.addEdge(S, col(j), -sum);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] >= 0) flow.addEdge(row(i), col(j), a[i][j]);
            else flow.addEdge(row(i), col(j), INF);
        }
    }

    cout << ans - flow.getFlow(S, T) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    solve();

    return 0;
}
