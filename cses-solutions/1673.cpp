#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MAXN = 2500, MAXM = 5000;
int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> rev_adj;
vector<bool> vis1, vis2;

int dist[MAXN + 5];
bool negcycle[MAXN + 5];
bool bellman_ford(){
    fill(dist + 1, dist + n + 1, -INF);

    dist[1] = 0;
    for(int i = 1; i <= n; ++i){
        bool diff = false;
        for(int u = 1; u <= n; ++u){
            for(const auto& p: adj[u]){
                int v, w; tie(v, w) = p;

                if(dist[u] + w > dist[v]){
                    if(i == n && vis1[v] && vis2[v]){
                        cout << "-1\n";
                        exit(0);
                    }
                    dist[v] = dist[u] + w;
                    diff = true;
                }
            }
        }

        if(!diff) break;
    }

    return true;
}

void dfs1(int u, vector<bool>& mark, const vector<vector<pair<int, int>>>& adjList){
    if(mark[u]) return;
    mark[u] = true;

    for(const auto& p: adj[u]){
        int v = p.first;
        dfs1(v, mark, adjList);
    }
}

void dfs2(int u, vector<bool>& mark, const vector<vector<int>>& adjList){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adjList[u]){
        dfs2(v, mark, adjList);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    rev_adj.resize(n + 1);

    for(int i = 1; i <= m; ++i){
        int a, b, x;
        cin >> a >> b >> x;

        adj[a].push_back({b, x});
        rev_adj[b].push_back(a);
    }

    vis1.resize(n + 1, false); vis2.resize(n + 1, false);
    dfs1(1, vis1, adj); dfs2(n, vis2, rev_adj);

    bellman_ford();

    cout << dist[n] << '\n';

    return 0;
}
