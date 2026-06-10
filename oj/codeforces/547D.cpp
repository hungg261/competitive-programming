/******************************************************************************
Link: https://codeforces.com/problemset/problem/547/D
Code: 547D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-11-19.48.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 2e5, MAXVAL = 2e5;
set<pair<int, int>> adj[2][MAXN + 5];
set<pair<int, int>> odds;

int n;
vector<pair<int, int>> P;
int delta[2][MAXN + 5];
char colors[MAXN + 5];

void hierholzer(int u, int b){
    while(!adj[b][u].empty()){
        int v, id; tie(v, id) = *adj[b][u].begin();
        adj[b][u].erase(adj[b][u].begin());
        adj[b ^ 1][v].erase({u, id});

        colors[id] = b ? 'r' : 'b';
        delta[b][u] += b ? 1 : -1;
        delta[b ^ 1][v] += b ? 1 : -1;

        hierholzer(v, b ^ 1);
    }
}

void dfs(){
    if(odds.empty()){
        for(int u = 1; u <= MAXN; ++u)
            hierholzer(u, 0);
        return;
    }

    int u, b; tie(u, b) = *odds.begin();
    int v, id; tie(v, id) = *adj[b][u].begin();

    {
        adj[b][u].erase(adj[b][u].begin());
        adj[b ^ 1][v].erase({u, id});

        odds.erase(odds.begin());
        if(adj[b ^ 1][v].size() & 1) odds.insert({v, b ^ 1});
        else odds.erase({v, b ^ 1});
    }

    dfs();
    if(delta[b ^ 1][v] < 0){
        colors[id] = 'r';
        delta[b][u]++;
        delta[b ^ 1][v]++;
    }
    else{
        colors[id] = 'b';
        delta[b][u]--;
        delta[b ^ 1][v]--;
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        adj[0][x].insert({y, i});
        adj[1][y].insert({x, i});

        P.emplace_back(x, y);
    }

    for(int b = 0; b < 2; ++b){
        for(int u = 1; u <= MAXN; ++u){
            if(adj[b][u].size() & 1){
                odds.insert({u, b});
            }
        }
    }

    dfs();

    for(int i = 0; i < n; ++i){
        cout << colors[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
