#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5;
int n, m, k;

struct Edge{ int v, w; };
vector<Edge> adj[MAXN + 5];

priority_queue<ll> dist[MAXN + 5];

void dijkstra(){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1].push(0);

    while(!pq.empty()){
        ll cost; int u;
        tie(cost, u) = pq.top();
        pq.pop();

        if(cost > dist[u].top()) continue;

        for(const Edge& e: adj[u]){
            ll newcost = cost + e.w;

            if(dist[e.v].size() < k){
                dist[e.v].push(newcost);
                pq.push({newcost, e.v});
            }
            else if(newcost < dist[e.v].top()){
                dist[e.v].pop();
                dist[e.v].push(newcost);
                pq.push({newcost, e.v});
            }
        }
    }
}

void print(priority_queue<ll>& p){
    vector<ll> s;
    while(!p.empty()){
        s.push_back(p.top());
        p.pop();
    }
    reverse(begin(s), end(s));
    for(ll e: s) cout << e << ' '; cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    dijkstra();

    for(int i = n; i <= n; ++i){
        print(dist[i]);
    }

    return 0;
}
