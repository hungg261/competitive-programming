/******************************************************************************
Link: https://judge.yosupo.jp/problem/scc
Code: scc
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-18.38.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, MAXM = 5e5;
int n, m;
vector<pair<int, int>> adj[MAXN + 5];

int low[MAXN + 5], tin[MAXN + 5], Timer = 0;
int onStack[MAXN + 5]; vector<int> sta;

int scc_id[MAXN + 5];
vector<pair<int, vector<int>>> scc;
void tarjan(int u, int prv_id){
    low[u] = tin[u] = ++Timer;
    onStack[u] = true;
    sta.push_back(u);

    for(const pair<int, int>& e: adj[u]){
        int v, id; tie(v, id) = e;
//        if(id == prv_id) continue;

        if(!tin[v]){
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
        }
        else if(onStack[v]) low[u] = min(low[u], tin[v]);
    }

    if(low[u] == tin[u]){
        scc.emplace_back(scc.size(), vector<int>{});
        while(onStack[u]){
            int v = sta.back();

            scc.back().second.push_back(v);
            scc_id[v] = scc.back().first;

            onStack[v] = false;
            sta.pop_back();
        }
    }
}

vector<int> dag[MAXN + 5];

int topoPos[MAXN + 5], Topo = 0;
void toposort(int u){
    if(topoPos[u]) return;
    topoPos[u] = -1;

    for(int v: dag[u]){
        toposort(v);
    }

    topoPos[u] = --Topo;
}

void condense(){
    for(int u = 0; u < n; ++u){
        for(const pair<int, int>& e: adj[u]){
            int v = e.first;
            if(scc_id[u] != scc_id[v])
                dag[scc_id[u]].push_back(scc_id[v]);
        }
    }

    for(int u = 0; u < (int)scc.size(); ++u){
        sort(dag[u].begin(), dag[u].end());
        dag[u].erase(unique(dag[u].begin(), dag[u].end()), dag[u].end());
    }

    for(int u = 0; u < (int)scc.size(); ++u)
        toposort(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
    }

    for(int u = 0; u < n; ++u){
        if(!tin[u]){
            tarjan(u, -1);
        }
    }

    condense();
    sort(scc.begin(), scc.end(), [&](auto& x, auto& y){ return topoPos[x.first] < topoPos[y.first]; });

    cout << (int)scc.size() << "\n";
    for(const pair<int, vector<int>>& p: scc){
        const vector<int>& vec = p.second;

        cout << (int)vec.size() << " ";
        for(int x: vec) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
