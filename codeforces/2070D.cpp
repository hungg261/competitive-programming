#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN = 3e5;
vector<int> adj[MAXN + 5];
int h[MAXN + 5], par[MAXN + 5], dp[MAXN + 5];
vector<int> level[MAXN + 5];

void dfs(int u, int prv){
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        level[h[v]].push_back(v);
        dfs(v, u);
    }
}

const int MOD = 998244353;
void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        level[i].clear();
        adj[i].clear();
        h[i] = 0;
        par[i] = 0;
        dp[i] = 0;
    }
    for(int i = 2; i <= n; ++i){
        int p; cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);

        par[i] = p;
    }
    dfs(1, 0);

    int sum_last = 0;
    dp[1] = 1;
    for(int u: level[1]){
        dp[u] = 1;
        ++sum_last;
    }

    for(int l = 2; l <= n; ++l){
        int acc = 0;
        for(int u: level[l]){
            dp[u] = (1LL * sum_last - dp[par[u]]) % MOD;
            acc = (1LL * acc + dp[u]) % MOD;
        }
        sum_last = acc;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = (1LL * ans + dp[i]) % MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
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
