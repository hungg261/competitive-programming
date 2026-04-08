/******************************************************************************
Link: https://oj.vnoi.info/problem/demen_08_graphprob
Code: demen_08_graphprob
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-07-20.05.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
bitset<MAXN> dp[MAXN];
int n, m, q;
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

//    for(int u = 1; u <= scc_cnt; ++u){
//        for(int v: dag[u]){
//            cout << u << ' ' << v << '\n';
//        }
//    }
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

    for(int u = 1; u <= scc_cnt; ++u){
        dp[u][u] = true;
        for(int v: dag[u]){
            dp[u][v] = true;
        }
    }

    reverse(begin(topo), end(topo));
    for(int u: topo){
        for(int v: dag[u]){
            dp[u] |= dp[v];
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if(scc_id[a] == scc_id[b]) cout << "YES\n";
        else if(dp[scc_id[a]][scc_id[b]]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/*
4 4 3
1 2
2 3
3 1
4 3
1 3
1 4
4 1

YES
NO
YES
*/
