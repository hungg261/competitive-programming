#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 5e5;
int h[MAXN + 5], diff[MAXN + 5], par[MAXN + 5];
vector<int> adj[MAXN + 5];

int dfs(int u, int prv){
    int deepest = h[u];
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        par[v] = u;
        deepest = max(deepest, dfs(v, u));
    }

    diff[h[u]]++;
    diff[deepest + 1]--;

    return deepest;
}

bool mark[MAXN + 5];
void toRoot(int u, int &ans){
    while(u != 0){
        if(mark[u]) break;
        mark[u] = true;

        ++ans;
        u = par[u];
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i <= n; ++i){
        adj[i].clear();
        diff[i] = 0;
        mark[i] = 0;
        par[i] = 0;
    }
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    int prefix = 0, best = 0, target_depth = -1e9;
    for(int d = 0; d <= n; ++d){
        prefix += diff[d];
        if(prefix > best){
            target_depth = d;
            best = prefix;
        }
    }

    int res = 0;
    for(int u = 1; u <= n; ++u){
        if(h[u] == target_depth){
            toRoot(u, res);
        }
    }

    cout << (n - res) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    cerr << fixed << setprecision(9) << "[Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s]\n";
    return 0;
}
/*
1
10
1 2
1 3
1 4
2 5
2 6
3 8
6 7
8 9
8 10
*/
