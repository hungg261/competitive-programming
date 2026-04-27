/******************************************************************************
Link: https://codeforces.com/contest/1328/problem/E
Code: 1328E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-27-10.25.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n;
vector<int> adj[MAXN + 5];

int par[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5], Timer = 0;
void dfs(int u, int prv){
    tin[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;

        par[v] = u;
        dfs(v, u);
    }

    tout[u] = Timer;
}

bool inSubtree(int u, int v){ // is v in subtree of u? :33
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void query(){
    int k; cin >> k;

    vector<int> T;
    for(int i = 1; i <= k; ++i){
        int u; cin >> u;
        T.push_back(par[u]);
    }

    sort(begin(T), end(T), [](int u, int v){
            return tin[u] < tin[v];
         });

    for(int i = 1; i < k; ++i){
        if(!inSubtree(T[i - 1], T[i])){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    par[1] = 1;

    while(q--){
        query();
    }

    return 0;
}
