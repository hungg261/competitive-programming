/******************************************************************************
Link: https://oj.uz/problem/view/JOI18_commuter_pass
Code: JOI18_commuter_pass
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-17-09.32.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n, m;
vector<pair<int, int>> adj[MAXN + 5];
int S, T, U, V;
int distS[MAXN + 5], distT[MAXN + 5];
int distU[MAXN + 5], distV[MAXN + 5];
int dpU[MAXN + 5], dpV[MAXN + 5];

void dijkstra(int s, int dist[]){
    fill(dist + 1, dist + n + 1, LLONG_MAX / 2);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        int cost, u; tie(cost, u) = pq.top();
        pq.pop();

        if(cost != dist[u]) continue;

        for(const pair<int, int>& e: adj[u]){
            int v, w; tie(v, w) = e;
            int newCost = cost + w;
            if(newCost < dist[v]){
                dist[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    cin >> S >> T >> U >> V;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dijkstra(S, distS); dijkstra(T, distT);
    dijkstra(U, distU); dijkstra(V, distV);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});

    memset(dpU, 0x3f, sizeof dpU);
    memset(dpV, 0x3f, sizeof dpV);
    dpU[S] = distU[S];
    dpV[S] = distV[S];
    vector<int> vis(n + 1, false);

    int ans = distU[V];
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        if(distS[u] + distT[u] == distS[T]){
            ans = min(ans, dpU[u] + distV[u]);
            ans = min(ans, dpV[u] + distU[u]);
        }

        for(const pair<int, int>& e: adj[u]){
            int v, w; tie(v, w) = e;
            if(distS[u] + w != distS[v]) continue;

            dpU[v] = min({dpU[v], dpU[u], distU[v]});
            dpV[v] = min({dpV[v], dpV[u], distV[v]});
            if(!vis[v]) pq.push({distS[v], v});
        }
    }

    cout << ans << "\n";

    return 0;
}
