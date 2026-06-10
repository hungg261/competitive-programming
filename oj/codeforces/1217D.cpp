/******************************************************************************
Link: https://codeforces.com/contest/1217/problem/D
Code: 1217D
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-09-20.59.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000, MAXM = 5000;
int n, m;
vector<pair<int, int>> edges;
vector<pair<int, int>> adj[MAXN + 5];

int mark[MAXN + 5];
bool dfs_cycle(int u){
    if(mark[u] == 2) return false;
    mark[u] = 1;

    for(const pair<int, int>& p: adj[u]){
        int v = p.first;
        if(mark[v] == 1) return true;
        else if(mark[v] == 0){
            if(dfs_cycle(v)) return true;
        }
    }

    mark[u] = 2;
    return false;
}

namespace Stress{

vector<int> adj[MAXN + 5];
int mark[MAXN + 5];
bool dfs_cycle(int u){
    if(mark[u] == 2) return false;
    mark[u] = 1;

    for(int v: adj[u]){
        if(mark[v] == 1) return true;
        else if(mark[v] == 0){
            if(dfs_cycle(v)) return true;
        }
    }

    mark[u] = 2;
    return false;
}

bool check(const vector<int>& c){
    int mx = *max_element(begin(c), end(c));
    vector<vector<int>> groups(mx + 1);
    for(int i = 0; i < m; ++i){
        groups[c[i]].push_back(i);
    }

    for(int g = 1; g <= mx; ++g){
        for(int u = 1; u <= n; ++u) adj[u].clear();
        for(int idx: groups[g]){
            adj[edges[idx].first].push_back(edges[idx].second);
        }

        for(int u = 1; u <= n; ++u) mark[u] = false;
        for(int u = 1; u <= n; ++u){
            if(!mark[u] && dfs_cycle(u)) return false;
        }
    }
    return true;
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        edges.emplace_back(a, b);
        adj[a].push_back({b, i});
    }
    vector<int> c(m, 0);
    for(int u = 1; u <= n; ++u){
        if(dfs_cycle(u)){
            for(int i = 0; i < m; ++i){
                c[i] = 1;
                if(!Stress::check(c)) c[i] = 2;
            }

            cout << "2\n";
            for(int i = 0; i < m; ++i) cout << c[i] << " ";
            return 0;
        }
    }

    cout << "1\n";
    for(int i = 0; i < m; ++i) cout << "1 ";

    return 0;
}
