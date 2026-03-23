#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];

bool visited[MAXN + 5];
void topological_sort(int u, vector<int>& topo){
    if(visited[u]) return;
    visited[u] = true;

    for(int v: adj[u])
        topological_sort(v, topo);

    topo.push_back(u);
}

void find_scc(int u, vector<int>& scc_id, const int& scc_count){
    if(scc_id[u] != 0) return;
    scc_id[u] = scc_count;

    for(int v: rev_adj[u])
        find_scc(v, scc_id, scc_count);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int e = 1; e <= m; ++ e){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    vector<int> topo;
    for(int i = 1; i <= n; ++i) if(!visited[i]) topological_sort(i, topo);
    reverse(begin(topo), end(topo));

    vector<int> scc_id(n + 1);
    int scc_count = 0;
    for(int u: topo){
        if(scc_id[u] == 0){
            ++scc_count;
            find_scc(u, scc_id, scc_count);
        }
    }

    cout << scc_count << '\n';
    for(int i = 1; i <= n; ++i){
        cout << scc_id[i] << ' ';
    }

    return 0;
}
