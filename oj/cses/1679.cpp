#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<int> adj[MAXN + 5];

int mark[MAXN + 5];
vector<int> topo_order;
bool dfs(int u){
    mark[u] = 1;
    for(int v: adj[u]){
        if(mark[v] == 0){ if(!dfs(v)) return false; }
        else if(mark[v] == 1) return false;
    }
    mark[u] = 2;

    topo_order.push_back(u);
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    for(int i = 1; i <= n; ++i){
        if(mark[i] == 0 && !dfs(i)){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    reverse(topo_order.begin(), topo_order.end());
    for(int node: topo_order) cout << node << ' ';

    return 0;
}
