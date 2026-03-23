/******************************************************************************
Link: https://cses.fi/problemset/task/1693
Code: 1693
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-28-07.30.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void fail(){
    cout << "IMPOSSIBLE\n";
    exit(0);
}

const int MAXN = 1e5;
int n, m;
set<int> adj[MAXN + 5];
int indeg[MAXN + 5];

vector<int> res;
void dfs(int u){
    while(!adj[u].empty()){
        int v = *adj[u].begin();
        adj[u].erase(v);

        dfs(v);
    }

    res.push_back(u);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1693.INP","r",stdin);
    //freopen("1693.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        ++indeg[b];
    }

    int invalid = 0;
    for(int u = 1; u <= n; ++u){
        if(abs(indeg[u] - (int) adj[u].size()) == 1) ++invalid;
        else if((int) adj[u].size() != indeg[u]) fail();
    }

    if(invalid != 0 && invalid != 2) fail();

    dfs(1);
    if(res[0] != n) fail();
    for(int u = 1; u <= n; ++u){
        if(!adj[u].empty()) fail();
    }

    reverse(begin(res), end(res));
    for(int node: res){
        cout << node << ' ';
    }

    return 0;
}
