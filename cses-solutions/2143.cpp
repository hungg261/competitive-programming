/******************************************************************************
Link: https://cses.fi/problemset/task/2143
Code: 2143
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-25-13.41.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
int n, m, q;
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];

vector<int> topo;
bool mark[MAXN + 5];
void dfs1(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        dfs1(v);
    }

    topo.push_back(u);
}

int scc_id[MAXN + 5], scc_cnt = 0;
void kosaraju(int u){
    if(scc_id[u]) return;
    scc_id[u] = scc_cnt;

    for(int v: rev_adj[u]){
        kosaraju(v);
    }
}

vector<int> dag[MAXN + 5];
vector<int> rev_dag[MAXN + 5];
void compressDAG(){
    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            if(scc_id[u] != scc_id[v]){
                dag[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }

    for(int u = 1; u <= scc_cnt; ++u){
        sort(begin(dag[u]), end(dag[u]));
        dag[u].erase(unique(begin(dag[u]), end(dag[u])), end(dag[u]));

        for(int v: dag[u]){
            rev_dag[v].push_back(u);
        }
    }
}

void toposort(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: dag[u]){
        toposort(v);
    }

    topo.push_back(u);
}

bitset<MAXN + 5> dp[MAXN + 5];
void compute(){
    topo.clear();
    for(int u = 1; u <= scc_cnt; ++u) mark[u] = false;
    for(int u = 1; u <= scc_cnt; ++u){
        if(!mark[u]) toposort(u);
    }

    for(int v: topo){
        dp[v][v] = 1;
        for(int u: rev_dag[v]){
            dp[u] |= dp[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
        if(!mark[i]) dfs1(i);

    reverse(begin(topo), end(topo));
    for(int u: topo){
        if(!scc_id[u]){
            ++scc_cnt;
            kosaraju(u);
        }
    }
    compressDAG();
    compute();

    while(q--){
        int a, b;
        cin >> a >> b;

        if(scc_id[a] == scc_id[b]) cout << "YES\n";
        else cout << (dp[scc_id[a]][scc_id[b]] ? "YES\n" : "NO\n");
    }

    return 0;
}
