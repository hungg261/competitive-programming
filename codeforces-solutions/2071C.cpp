#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN + 5];

vector<int> res;
void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }

    res.push_back(u);
}

void solve(){
    int n, st, en;
    cin >> n >> st >> en;

    for(int i = 1; i <= n; ++i){
        adj[i].clear();
    }
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(en, 0);
    for(int e: res) cout << e << ' '; cout << '\n';
    res.clear();
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
