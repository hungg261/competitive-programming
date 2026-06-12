/******************************************************************************
Link: https://cses.fi/problemset/task/1700/
Code: 1700
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-12-21.40.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int SHIFT = 2654435769;
const int MAXN = 1e5;
int n;
vector<int> adj[MAXN + 5];

#define ull unsigned long long

ull shift(ull x){
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x + SHIFT;
}

ull dfs(int u, int prv){
    ull H = 1;
    for(int v: adj[u]){
        if(v == prv) continue;
        H += shift(dfs(v, u));
    }
    return H;
}

ull getHash(){
    for(int u = 1; u <= n; ++u) adj[u].clear();
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return dfs(1, -1);
}

void solve(){
    cin >> n;
    cout << (getHash() == getHash() ? "YES" : "NO") << "\n";
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
