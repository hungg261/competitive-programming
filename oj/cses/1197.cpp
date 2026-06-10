#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2500;
int n, m;

struct Edge{ int v, w; };
vector<Edge> adj[MAXN + 5];

int dist[MAXN + 5], parent[MAXN + 5];

bool vis[MAXN + 5];
vector<int> res;
void dfs(int cur){
    if(vis[cur]){
        res.push_back(cur);
        return;
    }
    vis[cur] = true;

    res.push_back(cur);
    dfs(parent[cur]);
}

void bellman_ford(){
    memset(dist, 63, sizeof dist);
    dist[1] = 0;

    int last;
    for(int i = 1; i <= n; ++i){
        last = -1;
        for(int u = 1; u <= n; ++u){
            for(const Edge& e: adj[u]){
                if(dist[u] + e.w < dist[e.v]){
                    dist[e.v] = dist[u] + e.w;
                    parent[e.v] = u;
                    last = e.v;
                }
            }
        }

        if(last == -1){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; ++i){
        last = parent[last];
    }
    dfs(last);

    reverse(begin(res), end(res));
    for(int u: res) cout << u << ' ';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});

    }

    bellman_ford();

    return 0;
}
