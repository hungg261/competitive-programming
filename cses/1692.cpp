/******************************************************************************
Link: https://cses.fi/problemset/task/1692
Code: 1692
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-28-08.38.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n;

set<int> adj[1 << MAXN];

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
    //freopen("1692.INP","r",stdin);
    //freopen("1692.OUT","w",stdout);
    cin >> n;

    if(n == 1){
        cout << "01";
        return 0;
    }

    for(int mask = 0; mask < (1 << (n - 1)); ++mask){
        adj[mask].insert((mask << 1) & ((1 << (n - 1)) - 1));
        adj[mask].insert((mask << 1 | 1) & ((1 << (n - 1)) - 1));
    }

    dfs(0);

    cout << string(n - 2, '0');
    reverse(begin(res), end(res));
    for(int node: res){
        cout << (node & 1);
    }

    return 0;
}
