/******************************************************************************
Link: https://cses.fi/problemset/task/1691
Code: 1691
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-27-22.51.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
set<int> adj[MAXN + 5];
int n, m;

bool check1(){
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() & 1) return false;
    }
    return true;
}

bool check2(){
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() > 0) return false;
    }
    return true;
}

vector<int> res;
void dfs(int u){
    while(!adj[u].empty()){
        int v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);

        dfs(v);
    }

    res.push_back(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1691.INP","r",stdin);
    //freopen("1691.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    if(!check1()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(1);

    if(!check2()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }


    for(int node: res){
        cout << node << ' ';
    }

    return 0;
}
