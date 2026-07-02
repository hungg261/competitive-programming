/******************************************************************************
Link: https://oj.uz/problem/view/JOI23_passport
Code: JOI23_passport
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-02-14.18.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n;
vector<int> adj[MAXN * 4 + 5];
int ids[MAXN + 5];

void build(int id, int l, int r){
    if(l == r){
        ids[l] = id;
        return;
    }

    adj[id << 1].push_back(id);
    adj[id << 1 | 1].push_back(id);

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void add(int id, int l, int r, int u, int v, int t){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        adj[id].push_back(ids[t]);
        return;
    }

    int mid = (l + r) >> 1;
    add(id << 1, l, mid, u, v, t);
    add(id << 1 | 1, mid + 1, r, u, v, t);
}

int dist[2][MAXN * 4 + 5];
void dijkstra(int s, int d[]){
    s = ids[s];

    fill(d + 1, d + n * 4 + 1, INT_MAX / 2);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        int cost, u; tie(cost, u) = pq.top(); pq.pop();

        if(cost != d[u]) continue;

        for(int v: adj[u]){
            int newCost = cost + (v == u / 2 ? 0 : 1);
            if(newCost < d[v]){
                d[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }
}

int dp[MAXN * 4 + 5];
void solve(){
    dijkstra(1, dist[0]);
    dijkstra(n, dist[1]);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int u = 1; u <= n * 4; ++u){
        dp[u] = INT_MAX / 2;
    }
    for(int i = 1; i <= n; ++i){
        int u = ids[i];
        dp[u] = dist[0][u] + dist[1][u] - (1 < i && i < n);
        if(dp[u] < INT_MAX / 2){
            pq.push({dp[u], u});
        }
    }

    while(!pq.empty()){
        int cost, u; tie(cost, u) = pq.top(); pq.pop();
        if(cost != dp[u]) continue;

        for(int v: adj[u]){
            int newCost = cost + (v == u / 2 ? 0 : 1);
            if(newCost < dp[v]){
                dp[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    build(1, 1, n);
    for(int u = 1; u <= n; ++u){
        int l, r;
        cin >> l >> r;

        add(1, 1, n, l, r, u);
    }

    solve();

    int q; cin >> q;
    while(q--){
        int u; cin >> u;
        u = ids[u];
        cout << (dp[u] >= INT_MAX / 2 ? -1 : dp[u]) << "\n";
    }

    return 0;
}
