#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 2e5;
vector<int> adj[MAXN + 5];

void dfs(int u, int prv, bool downward){
    for(int v: adj[u]){
        if(v == prv) continue;

        if(downward) cout << u << ' ' << v << '\n';
        else cout << v << ' ' << u << '\n';

        dfs(v, u, !downward);
    }
}

void solve(){
    int n;
    cin >> n;

    for(int u = 1; u <= n; ++u){
        adj[u].clear();
    }
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u){
        if((int)adj[u].size() == 2){
            int v1 = adj[u][0], v2 = adj[u][1];

            cout << "YES\n";
            cout << v1 << ' ' << u << '\n';
            cout << u << ' ' << v2 << '\n';
            dfs(v1, u, true);
            dfs(v2, u, false);
            return;
        }
    }

    cout << "NO\n";
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
