#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4, MAXM = 1e5;
int n, m;
bool visited[MAXN + 5], in_scc[MAXN + 5];
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];

vector<int> order;
void dfs1(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (int v : adj[u]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    if (in_scc[u]) return;
    in_scc[u] = true;
    for (int v : rev_adj[u]) dfs2(v);
}

void solve() {
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs1(i);

    int ans = 0;
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!in_scc[u]) {
            dfs2(u);
            ++ans;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    solve();
    
    return 0;
}
