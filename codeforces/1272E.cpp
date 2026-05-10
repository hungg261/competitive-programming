/******************************************************************************
Link: https://codeforces.com/contest/1272/problem/E
Code: 1272E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-09.06.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, a[MAXN + 5];
vector<int> adj[MAXN + 5];

int dist[MAXN + 5], res[MAXN + 5];
void solve(){
    for(int r = 0; r < 2; ++r){
        memset(dist, 0x3f, sizeof dist);
        queue<pair<int, int>> que;
        for(int i = 1; i <= n; ++i){
            if(a[i] % 2 == r){
                que.push({i, 0});
                dist[i] = 0;
            }
        }

        while(!que.empty()){
            int u, cost;
            tie(u, cost) = que.front(); que.pop();

            if(dist[u] != cost) continue;

            for(int v: adj[u]){
                int newD = cost + 1;
                if(newD < dist[v]){
                    dist[v] = newD;
                    que.push({v, newD});
                }
            }
        }

        for(int i = 1; i <= n; ++i){
            if(a[i] % 2 != r){
                res[i] = dist[i] == dist[0] ? -1 : dist[i];
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];

        if(1 <= i - a[i]) adj[i - a[i]].push_back(i);
        if(i + a[i] <= n) adj[i + a[i]].push_back(i);
    }

    solve();

    return 0;
}
