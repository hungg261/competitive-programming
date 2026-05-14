/******************************************************************************
Link: https://codeforces.com/contest/999/problem/E
Code: 999E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-14.18.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int n, m, s;
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];

vector<int> topo;
bool mark[MAXN + 5];
void dfs(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        dfs(v);
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
int indeg[MAXN + 5];
void compress_dag(){
    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            if(scc_id[u] != scc_id[v]){
                dag[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }

    for(int i = 1; i <= scc_cnt; ++i){
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }

    for(int u = 1; u <= scc_cnt; ++u){
        for(int v: dag[u]){
            ++indeg[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u){
        if(!mark[u]) dfs(u);
    }
    reverse(begin(topo), end(topo));

    for(int u: topo){
        if(scc_id[u] == 0){
            ++scc_cnt;
            kosaraju(u);
        }
    }

    compress_dag();

    int res = 0;
    for(int i = 1; i <= scc_cnt; ++i){
        if(indeg[i] == 0 && i != scc_id[s]){
            ++res;
        }
    }

    cout << res << "\n";

    return 0;
}

