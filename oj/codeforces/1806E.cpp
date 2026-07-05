/******************************************************************************
Link: https://codeforces.com/problemset/problem/1806/E
Code: 1806E
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-05-15.31.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, BOUND = sqrt(MAXN) + 1;
int MAXSQRT;

vector<int> adj[MAXN + 5];
int a[MAXN + 5], n;
int par[MAXN + 5];

vector<vector<vector<int>>> memo;
int atRow[MAXN + 5], atPos[MAXN + 5];
int rowCnt[MAXN + 1], curID = 0;

int cntRow[MAXN + 5], rowID[MAXN + 5];

void bfs(){
    queue<pair<int, int>> que; que.push({1, 0});
    cntRow[0] = 1;
    while(!que.empty()){
        int u, h; tie(u, h) = que.front(); que.pop();
        for(int v: adj[u]){
            par[v] = u;

            ++cntRow[h + 1];

            que.push({v, h + 1});
        }
    }
}

void build(){
    queue<pair<int, int>> que; que.push({1, 0});

    while(!que.empty()){
        int u, h; tie(u, h) = que.front(); que.pop();
        for(int v: adj[u]){
            que.push({v, h + 1});
        }

        if(cntRow[h] <= MAXSQRT){
            if(!rowID[h]) rowID[h] = ++curID;
            atRow[u] = rowID[h];
            atPos[u] = rowCnt[rowID[h]]++;
        }
        else atRow[u] = 0;
    }
}

int query(int u, int v){
    if(u > v) swap(u, v);

    if(u == 0 || v == 0) return 0;
    assert(atRow[u] == atRow[v]);

    int id = atRow[u];
    if(id){
        int res = memo[id][atPos[u]][atPos[v]];
        if(res) return res;
    }

    int res = a[u] * a[v] + query(par[u], par[v]);
    if(id) memo[id][atPos[u]][atPos[v]] = res;

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;

    MAXSQRT = sqrt(n) + 1;

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int v = 2; v <= n; ++v){
        int u; cin >> u;
        adj[u].push_back(v);
    }

    bfs();
    build();

    memo.resize(curID + 1);
    for(int h = 1; h <= curID; ++h){
        memo[h].resize(rowCnt[h]);
        for(vector<int>& v: memo[h]){
            v.resize(rowCnt[h]);
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << query(u, v) << "\n";
    }

    return 0;
}
