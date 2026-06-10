/******************************************************************************
Link: https://codeforces.com/contest/2014/problem/E
Code: 2014E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-17.48.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define dp dist[type]

struct EdgeTo{
    int v, w;

    tuple<int, int> get() const{
        return make_tuple(v, w);
    }
};

struct State{
    int value, node, rided;

    bool operator > (const State& other) const{
        return value > other.value;
    }

    tuple<int, int, int> get() const{
        return make_tuple(value, node, rided);
    }
};

const int MAXN = 2e5;
const int INF = 1e15;
int n, m, h;
int horse[MAXN + 5];
vector<EdgeTo> adj[MAXN + 5];

int dist[2][MAXN + 5][2];
void dijkstra(int type, int st){
    for(int u = 1; u <= n; ++u){
        dp[u][0] = dp[u][1] = INF;
    }
    dp[st][0] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, st, false});

    while(!pq.empty()){
        int cost, u, rided;
        tie(cost, u, rided) = pq.top().get();
        pq.pop();

        if(dp[u][rided] != cost) continue;

        if(horse[u]) rided = true;
        for(const EdgeTo& dest: adj[u]){
            int v, w; tie(v, w) = dest.get();
            if(rided) w /= 2;

            int newCost = cost + w;
            if(newCost < dp[v][rided]){
                dp[v][rided] = newCost;
                pq.push({newCost, v, rided});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> h;

    for(int u = 1; u <= n; ++u){
        adj[u].clear();
        horse[u] = 0;
    }
    for(int i = 1; i <= h; ++i){
        int hpos;
        cin >> hpos;

        horse[hpos] = true;
    }
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra(0, 1);
    dijkstra(1, n);

    int ans = INF;
    for(int u = 1; u <= n; ++u){
        ans = min(ans,
                  max(min(dist[0][u][0], dist[0][u][1]),
                      min(dist[1][u][0], dist[1][u][1]))
                  );
    }

    if(ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}
