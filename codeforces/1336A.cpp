#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, k;
int h[MAXN + 5], sz[MAXN + 5];
vector<int> adj[MAXN + 5];

void dfs(int u, int prv){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

struct cmp{
    bool operator () (int u, int v){
        return h[u] - sz[u] < h[v] - sz[v];
    }
};

bool mark[MAXN + 5];
void propagate(int u, int prv, int tourism, int &ans){
    if(!mark[u]) tourism++;
    else ans += tourism;

    for(int v: adj[u]){
        if(v == prv) continue;
        propagate(v, u, tourism, ans);
    }
}

void solve(){
    priority_queue<int, vector<int>, cmp> pq;
    for(int u = 2; u <= n; ++u) pq.push(u);

    while(k--){
        mark[pq.top()] = true;
        pq.pop();
    }

    int ans = 0;
    propagate(1, 0, 0, ans);
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    solve();

    return 0;
}
