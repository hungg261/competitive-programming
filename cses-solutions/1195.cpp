#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<pair<int, int>> adj[MAXN + 5];

struct State{
    int minCost, u;
    bool discounted;

    void assign(int& x, int& y, bool& z) const{ x = minCost; y = u; z = discounted; }

    bool operator > (const State& other) const{ return this->minCost > other.minCost; }
};

int dist[2][MAXN + 5];
void dijkstra(int base){
    for(int i = 1; i <= n; ++i) dist[0][i] = dist[1][i] = INF;

    priority_queue<State, vector<State>, greater<>> pq;
    pq.push({0, base, false});
    dist[0][base] = dist[1][base] = 0;

    while(!pq.empty()){
        int curCost, u; bool discounted;
        pq.top().assign(curCost, u, discounted);
        pq.pop();

        if(curCost > dist[discounted][u]) continue;

        for(const auto& p: adj[u]){
            int v, w; tie(v, w) = p;
            int newCostUndiscounted = dist[0][u] + w;
            int newCostDiscounted = min(newCostUndiscounted, dist[1][u] + w);
            if(!discounted) newCostDiscounted = min(newCostDiscounted, dist[0][u] + w / 2);

            if(newCostDiscounted < dist[1][v]){
                dist[1][v] = newCostDiscounted;
                pq.push({newCostDiscounted, v, true});
            }
            if(newCostUndiscounted < dist[0][v]){
                dist[0][v] = newCostUndiscounted;
                pq.push({newCostUndiscounted, v, false});
            }
        }
    }

//    for(int i = 1; i <= n; ++i) cerr << dist[0][i] << ' ' << dist[1][i] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    dijkstra(1);

    cout << dist[1][n] << '\n';

    return 0;
}
