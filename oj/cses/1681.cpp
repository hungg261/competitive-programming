#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<int> adj[MAXN + 5];

vector<int> topo;
bool mark[MAXN + 5];
void topological_sort(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        topological_sort(v);
    }

    topo.push_back(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i) if(!mark[i]) topological_sort(i);
    reverse(begin(topo), end(topo));

    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0), trace(n + 1, -1);

    dp[1] = 1 % MOD;
    for(int i = 0; i < n; ++i){
        int u = topo[i];
        for(int v: adj[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
