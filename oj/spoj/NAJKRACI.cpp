/******************************************************************************
Link: https://www.spoj.com/problems/NAJKRACI
Code: NAJKRACI
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-17-16.53.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1500, MAXM = 5000;
const int MOD = 1e9 + 7;
int N, M;

struct EdgeTo{
    int v, w, id;
};
vector<EdgeTo> adj[MAXN + 5];

int ans[MAXM + 5];

int dist[MAXN + 5];
void solve(int S){
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});

    vector<int> topo;
    while(!pq.empty()){
        int cost, u; tie(cost, u) = pq.top();
        pq.pop();

        if(cost != dist[u]) continue;
        topo.push_back(u);

        for(const EdgeTo& e: adj[u]){
            int newCost = cost + e.w;
            if(newCost < dist[e.v]){
                dist[e.v] = newCost;
                pq.push({newCost, e.v});
            }
        }
    }

    vector<int> f(N + 1, 0);
    for(int i = 0; i < (int)topo.size(); ++i){
        int u = topo[i];
        if(!f[u]) f[u] = 1;
        for(const EdgeTo& e: adj[u]){
            if(dist[u] + e.w == dist[e.v])
                f[e.v] = (1LL * f[e.v] + f[u]) % MOD;
        }
    }

    vector<int> g(N + 1, 0);
    for(int i = (int)topo.size() - 1; i >= 0; --i){
        int u = topo[i];
        if(!g[u]) g[u] = 1;
        for(const EdgeTo& e: adj[u]){
            if(dist[u] + e.w == dist[e.v])
                g[u] = (1LL * g[u] + g[e.v]) % MOD;
        }
    }

    for(int u = 1; u <= N; ++u){
        for(const EdgeTo& e: adj[u]){
            if(dist[u] + e.w == dist[e.v]){
                ans[e.id] += 1LL * f[u] * g[e.v] % MOD;
                ans[e.id] %= MOD;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c, i});
    }

    for(int u = 1; u <= N; ++u){
        solve(u);
    }

    for(int i = 1; i <= M; ++i){
        cout << ans[i] << "\n";
    }

    return 0;
}
