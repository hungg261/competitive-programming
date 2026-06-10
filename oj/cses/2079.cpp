/******************************************************************************
Link: https://cses.fi/problemset/task/2079
Code: 2079
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-28-07.18.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int sz[MAXN + 5];
vector<int> adj[MAXN + 5];
int n;

void dfs(int u, int prev){
    sz[u] = 1;

    for(int v: adj[u]){
        if(v == prev) continue;

        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int prev){
    for(int v: adj[u]){
        if(v == prev) continue;

        if(sz[v] > n / 2){
            return centroid(v, u);
        }
    }

    return u;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2079.INP","r",stdin);
    //freopen("2079.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    int cen = centroid(1, 0);

    cout << cen << '\n';

    return 0;
}
