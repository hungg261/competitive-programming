#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MAXN = 1000, MAXM = 10000;
int n, m;
vector<vector<int>> adj, rev_adj;

bool visited[MAXN + 5];
void toposort(int u, vector<int>& topo, vector<vector<int>>& adj){
    if(visited[u]) return;
    visited[u] = true;
    
    for(int v: adj[u]){
        toposort(v, topo, adj);
    }
    
    topo.push_back(u);
}

void kosaraju(int u, const int& scc_count, vector<int>& scc_id){
    if(scc_id[u] != -1) return;
    scc_id[u] = scc_count;
    
    for(int v: rev_adj[u]){
        kosaraju(v, scc_count, scc_id);
    }
}

void solve(){
    vector<int> topo;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]) toposort(i, topo, adj);
    }
    reverse(begin(topo), end(topo));
    
    vector<int> scc_id(n + 1, -1);
    int scc_count = 0;
    for(int i: topo){
        if(scc_id[i] == -1){
            ++scc_count;
            kosaraju(i, scc_count, scc_id);
        }
    }
    
    vector<int> indeg(scc_count + 1, 0);
    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            if(scc_id[u] != scc_id[v]){
                ++indeg[scc_id[v]];
            }
        }
    }
    
    int ans = count(begin(indeg) + 1, end(indeg), 0);
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    solve();
    
    return 0;
}
