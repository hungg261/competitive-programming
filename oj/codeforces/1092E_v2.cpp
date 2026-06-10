/******************************************************************************
Link: https://codeforces.com/contest/1092/problem/E
Code: 1092E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-03-10.39.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, m, par[MAXN + 5], h[MAXN + 5];
vector<int> adj[MAXN + 5];
bool vis[MAXN + 5];

pair<int, int> furthest(int u, int prv){
    vis[u] = true;

    pair<int, int> far = {0, u};
    for(int v: adj[u]){
        if(v == prv) continue;

        par[v] = u;
        h[v] = h[u] + 1;

        pair<int, int> cand = furthest(v, u);
        far = max(far, {cand.first + 1, cand.second});
    }

    return far;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> centers;
    int res = 0;
    for(int u = 1; u <= n; ++u){
        if(!vis[u]){
            int p = furthest(u, -1).second,
                center, D;
            tie(D, center) = furthest(p, -1);

            if(h[center] < h[p]) swap(center, p);

            int cur = D;
            while(cur > D / 2){
                center = par[center];
                --cur;
            }

            centers.push_back({D, center});
            res += D;
        }
    }

    sort(begin(centers), end(centers), greater<pair<int, int>>());

    int cc = centers.size();
    for(int i = 1; i < cc; ++i){
        int u = centers[0].second,
            v = centers[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int D = furthest(furthest(1, -1).second, -1).first;

    cout << D << "\n";
    for(int i = 1; i < cc; ++i){
        int u = centers[0].second,
            v = centers[i].second;
        cout << u << " " << v << "\n";
    }

    return 0;
}
