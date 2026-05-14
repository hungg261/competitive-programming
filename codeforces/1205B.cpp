/******************************************************************************
Link: https://codeforces.com/contest/1205/problem/B
Code: 1205B
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-19.09.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n, a[MAXN + 5];

vector<int> adj[MAXN + 5];

int bfs(int s, int t){
    queue<int> que;
    map<int, int> dist;

    dist[s] = 0;
    que.push(s);

    while(!que.empty()){
        int u = que.front(); que.pop();

        for(int v: adj[u]){
            if((u == s && v == t) || (u == t && v == s))
                continue;

            if(!dist.count(v)){
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    return dist.count(t) ? dist[t] + 1 : LLONG_MAX;
}

void solve(){
    for(int b = 60; b >= 0; --b){
        vector<int> pos;
        for(int i = 1; i <= n; ++i){
            if(a[i] >> b & 1) pos.push_back(i);
        }

        if(pos.size() >= 3){
            cout << "3\n";
            return;
        }
        else if(pos.size() <= 1) continue;

        adj[pos[0]].push_back(pos[1]);
        adj[pos[1]].push_back(pos[0]);
    }

    int res = LLONG_MAX;
    for(int u = 1; u <= n; ++u){
        for(int v: adj[u]){
            res = min(res, bfs(u, v));
        }
    }

    cout << (res == LLONG_MAX ? -1 : res) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    solve();

    return 0;
}
