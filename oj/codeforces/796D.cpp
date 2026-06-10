/******************************************************************************
Link: https://codeforces.com/contest/796/problem/D
Code: 796D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-14-15.06.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int n, k, d;
vector<int> stations;
vector<pair<int, int>> adj[MAXN + 5];

struct State{
    int u, prv, left;
};

bool mark[MAXN + 5];
void bfs(){
    queue<State> que;

    for(int s: stations){
        adj[0].emplace_back(s, -1);
    }
    que.push({0, -1, d + 1});

    set<int> removed;
    while(!que.empty()){
        State e = que.front(); que.pop();

        for(const pair<int, int>& p: adj[e.u]){
            int v, idx; tie(v, idx) = p;
            if(v == e.prv) continue;

            if(mark[v]){
                if(idx > 0) removed.insert(idx);
                continue;
            }

            mark[v] = true;
            if(e.left) que.push({v, e.u, e.left - 1});
            else if(idx > 0) removed.insert(idx);
        }
    }

    cout << removed.size() << "\n";
    for(int e: removed) cout << e << " ";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> d;
    for(int i = 0; i < k; ++i){
        int p; cin >> p;
        stations.push_back(p);
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    bfs();

    return 0;
}
