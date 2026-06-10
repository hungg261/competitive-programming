/******************************************************************************
Link: https://codeforces.com/contest/449/problem/B
Code: 449B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-02-10.36.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct EdgeTo{
    int v, w;
    int idx;

    EdgeTo(int _v = -1, int _w = -1, int _i = 0):
        v(_v), w(_w), idx(_i){}

    bool operator < (const EdgeTo& other) const {
        return w < other.w || (w == other.w && idx < other.idx);
    }
};

const int MAXN = 1e5, MAXM = 3e5, MAXK = 1e5;
int n, m, k;
vector<EdgeTo> adj[MAXN + 5];
int mark[MAXK + 5], prv[MAXN + 5];

int dist[MAXN + 5];
void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    memset(dist, 0x3f, sizeof dist);

    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        int cost, u;
        tie(cost, u) = pq.top();
        pq.pop();

        if(cost != dist[u]) continue;

        for(const EdgeTo& e: adj[u]){
            int newCost = cost + e.w;
            if(newCost <= dist[e.v]){

                if(newCost < dist[e.v] || prv[e.v] != 0){
                    mark[prv[e.v]]--;
                    mark[e.idx]++;
                    prv[e.v] = e.idx;
                }

                if(newCost < dist[e.v]){
                    dist[e.v] = newCost;
                    pq.push({newCost, e.v});

                }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= k; ++i){
        if(!mark[i]) ++res;
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].emplace_back(b, c, 0);
        adj[b].emplace_back(a, c, 0);
    }

    for(int i = 1; i <= k; ++i){
        int s, c;
        cin >> s >> c;

        adj[1].emplace_back(s, c, i);
        adj[s].emplace_back(1, s, i);
    }

    solve();

    return 0;
}
