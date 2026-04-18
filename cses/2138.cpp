/******************************************************************************
Link: https://cses.fi/problemset/task/2138
Code: 2138
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-16-19.34.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
bitset<MAXN> dp[MAXN];
vector<int> adj[MAXN], rev_adj[MAXN];
int n, m;

vector<int> topo;
bool mark[MAXN];
void toposort(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        toposort(v);
    }

    topo.push_back(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        --a; --b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 0; i < n; ++i)
        toposort(i);

    for(int v: topo){
        dp[v][v] = true;
        for(int u: rev_adj[v]){
            dp[u] |= dp[v];
        }
    }

    for(int u = 0; u < n; ++u)
        cout << dp[u].count() << " ";

    return 0;
}
