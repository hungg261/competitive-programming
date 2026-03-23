#include<bits/stdc++.h>
#define cerr if(false)cerr
using namespace std;

const int MAXN = 1e5, MAXM = 1e5;
int n, m;
vector<int> adj[MAXN * 2 + 5], rev_adj[MAXN * 2 + 5];

int shift(int x){
    return x + MAXN + 1;
}

int unshift(int x){
    return x - MAXN - 1;
}

bool mark[MAXN * 2 + 5];
void toposort(int u, vector<int>& topo){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        toposort(v, topo);
    }

    topo.push_back(u);
}

int scc_id[MAXN * 2 + 5], scc_count = 0;
void kosaraju(int u){
    if(scc_id[u] != 0) return;
    scc_id[u] = scc_count;

    for(int v: rev_adj[u]){
        kosaraju(v);
    }
}

vector<int> dag[MAXN * 2 + 5], sccs[MAXN * 2 + 5];
void compress(){
    for(int u = shift(-n); u <= shift(n); ++u){
        if(unshift(u) == 0) continue;

        for(int v: adj[u]){
            if(scc_id[u] != scc_id[v]){
                dag[scc_id[u]].push_back(scc_id[v]);
            }
        }
        sccs[scc_id[u]].push_back(u);
    }

    for(int i = 1; i <= scc_count; ++i){
        sort(begin(dag[i]), end(dag[i]));
        dag[i].erase(unique(begin(dag[i]), end(dag[i])), end(dag[i]));
    }
}

void toposort_compressed(int u, vector<int>& topo){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: dag[u]){
        toposort_compressed(v, topo);
    }

    topo.push_back(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        char oa, ob; int a, b;
        cin >> oa >> a >> ob >> b;

        if(oa == '-') a = -a;
        if(ob == '-') b = -b;

        adj[shift(-a)].push_back(shift(b));
        adj[shift(-b)].push_back(shift(a));

        rev_adj[shift(b)].push_back(shift(-a));
        rev_adj[shift(a)].push_back(shift(-b));
    }

    vector<int> topo;
    for(int i = shift(-n); i <= shift(n); ++i){
        if(!mark[i] && unshift(i) != 0) toposort(i, topo);
    }
    reverse(begin(topo), end(topo));

    for(int u: topo){
        if(scc_id[u] == 0){
            ++scc_count;
            kosaraju(u);
        }
    }

    for(int u = shift(-n); u <= shift(n); ++u){
        if(unshift(u) == 0) continue;

        if(scc_id[u] == scc_id[shift(-unshift(u))]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    compress();
    topo.clear(); fill(mark + 1, mark + scc_count + 1, false);
    for(int i = 1; i <= scc_count; ++i){
        if(!mark[i]) toposort_compressed(i, topo);
    }

    vector<int> ans(n + 1, 0);
    for(int id: topo){
        for(int u: sccs[id]){
            int cur = unshift(u);

            if(ans[abs(cur)] != 0 || cur == 0) continue;

            ans[abs(cur)] = cur < 0 ? -1 : 1;
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << (ans[i] > 0 ? '+' : '-') << ' ';
    }

    return 0;
}
