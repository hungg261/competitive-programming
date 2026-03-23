/******************************************************************************
Link: https://codeforces.com/contest/20/problem/C
Code: 20C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-06-15.19.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
const int INF = 1e18;
int dist[MAXN + 5], par[MAXN + 5];

int n, m;
vector<pair<int, int>> adj[MAXN + 5];

void dijkstra(){
    fill(dist + 1, dist + n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int cost, u;
        tie(cost, u) = pq.top();
        pq.pop();

        if(dist[u] != cost) continue;

        for(const pair<int, int>& e: adj[u]){
            int v, w;
            tie(v, w) = e;

            int newCost = cost + w;
            if(newCost < dist[v]){
                dist[v] = newCost;
                par[v] = u;
                pq.push({newCost, v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dijkstra();

    if(dist[n] == INF){
        cout << "-1\n";
        return 0;
    }

    int cur = n;
    vector<int> res;
    while(cur){
        res.push_back(cur);
        cur = par[cur];
    }

    reverse(begin(res), end(res));
    for(int ele: res){
        cout << ele << ' ';
    }

    return 0;
}
