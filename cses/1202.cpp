#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<pair<int, int>> adj[MAXN + 5];

int mincost[MAXN + 5], ways[MAXN + 5], minf[MAXN + 5], maxf[MAXN + 5];
bool visited[MAXN + 5];
void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    memset(mincost, 0x3f, sizeof mincost);
    memset(minf, 0x3f, sizeof minf);
    mincost[1] = 0; ways[1] = 1; minf[1] = maxf[1] = 0;

    while(!pq.empty()){
        int cost, node; tie(cost, node) = pq.top();
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(const pair<int, int>& p: adj[node]){
            int dest, weight; tie(dest, weight) = p;
            int newcost = cost + weight;

            if(mincost[dest] == newcost){
                ways[dest] = (ways[dest] + ways[node]) % MOD;
                minf[dest] = min(minf[dest], minf[node] + 1);
                maxf[dest] = max(maxf[dest], maxf[node] + 1);
            }
            else if(mincost[dest] > newcost){
                mincost[dest] = newcost;
                ways[dest] = ways[node];
                minf[dest] = minf[node] + 1;
                maxf[dest] = maxf[node] + 1;

                pq.push({newcost, dest});
            }
        }
    }

    for(int i = n; i <= n; ++i){
        cout << mincost[i] << ' ' << ways[i] << ' ' << minf[i] << ' ' << maxf[i] << '\n';
    }
}

void solve(){

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    dijkstra();
    solve();

    return 0;
}
