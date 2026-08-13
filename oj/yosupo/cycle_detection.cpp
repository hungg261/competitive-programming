/******************************************************************************
Link: https://judge.yosupo.jp/problem/cycle_detection
Code: cycle_detection
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-10-16.25.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, id;

    bool operator < (const Edge& other) const {
        return u < other.u || (u == other.u && v < other.v);
    }
};

const int MAXN = 5e5;
vector<pair<int, int>> adj[MAXN + 5];
int n, m;

vector<int> cycle;
int mark[MAXN + 5];
bool dfs(int u){
    mark[u] = 1;
    for(const pair<int, int>& e: adj[u]){
        int v, idx; tie(v, idx) = e;
        if(mark[v] == 0){
            if(dfs(v)){
                cycle.push_back(v);
                return true;
            }
        }
        else if(mark[v] == 1){
            cycle.push_back(-v);
            return true;
        }
    }
    mark[u] = 2;

    return false;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    vector<Edge> edges;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        ++a; ++b;

        adj[a].push_back({b, i});
        edges.push_back({a, b, i});
    }
    sort(begin(edges), end(edges));

    for(int u = 1; u <= n; ++u){
        if(mark[u] == 0 && dfs(u)){

            for(int i = 0; i < (int)cycle.size(); ++i){
                if(cycle[i] < 0){
                    cycle[i] *= -1;
                    cycle.erase(find(begin(cycle) + i + 1, end(cycle), cycle[i]), end(cycle));
                    break;
                }
            }

            int sz = cycle.size();
            cout << sz << "\n";
            reverse(begin(cycle), end(cycle));

            for(int i = 0; i < sz; ++i){
                int pos = lower_bound(begin(edges), end(edges), Edge{cycle[i], cycle[(i + 1) % sz], -1})->id;
                cout << pos << "\n";
            }
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
