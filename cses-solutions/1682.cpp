/******************************************************************************
Link: https://cses.fi/problemset/task/1682
Code: 1682
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-26-21.47.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN + 5], rev_adj[MAXN + 5];
int n, m;

vector<int> topo1;
bool mark[MAXN + 5];
void dfs1(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        dfs1(v);
    }

    topo1.push_back(u);
}

int scc_id[MAXN + 5], scc_cnt = 0;
void kosaraju(int u){
    if(scc_id[u] != 0) return;
    scc_id[u] = scc_cnt;

    for(int v: rev_adj[u]){
        kosaraju(v);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1682.INP","r",stdin);
    //freopen("1682.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) dfs1(i);

    memset(mark, 0, sizeof mark);
    reverse(begin(topo1), end(topo1));
    for(int i: topo1){
        if(scc_id[i] == 0){
            ++scc_cnt;
            kosaraju(i);
        }
    }

    if(scc_cnt == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
        for(int u = 1; u <= n; ++u){
            for(int v: adj[u]){
                if(scc_id[u] != scc_id[v]){
                    cout << v << ' ' << u << '\n';
                    return 0;
                }
            }
        }

        for(int u = 2; u <= n; ++u){
            if(scc_id[u] != scc_id[1]){
                cout << 1 << ' ' << u << '\n';
                break;
            }
        }
    }

    return 0;
}
