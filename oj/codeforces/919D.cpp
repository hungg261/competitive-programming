/******************************************************************************
Link: https://codeforces.com/problemset/problem/919/D
Code: 919D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-21-13.30.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int n, m;
vector<int> adj[MAXN + 5];
string str;

int vis[MAXN + 5];
void check(int u){
    if(vis[u] == 1){
        cout << "-1\n";
        exit(0);
    }
    else if(vis[u] == 2) return;

    vis[u] = 1;

    for(int v: adj[u]){
        check(v);
    }

    vis[u] = 2;
}

vector<int> topo;
bool mark[MAXN + 5];
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
    cin >> n >> m >> str;
    str = "#" + str;

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i){
        check(i);
    }

    for(int i = 1; i <= n; ++i){
        if(!mark[i]) toposort(i);
    }
    reverse(begin(topo), end(topo));

    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    for(int u: topo){
        dp[u][str[u] - 'a'] = 1;
    }

    for(int i = 0; i < n; ++i){
        int u = topo[i];
        for(int v: adj[u]){
            int c = str[v] - 'a';
            for(int k = 0; k < 26; ++k){
                dp[v][k] = max(dp[v][k], dp[u][k] + (k == c));
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, *max_element(begin(dp[i]), end(dp[i])));
    }

    cout << ans << '\n';

    return 0;
}
