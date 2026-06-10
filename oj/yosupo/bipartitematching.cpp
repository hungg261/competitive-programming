/******************************************************************************
Link: https://judge.yosupo.jp/problem/bipartitematching
Code: bipartitematching
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-22-23.04.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Hopcroft_Karp{
    int n, m;
    vector<vector<int>> adj;
    vector<int> dist, L, R;

    Hopcroft_Karp(int _n, int _m): n(_n), m(_m){
        adj.resize(n + 1);
        dist.resize(n + 1, 0);
        L.resize(n + 1, 0);
        R.resize(m + 1, 0);
    }

    void add_edge(int a, int b){
        adj[a].push_back(b);
    }

    bool bfs(){
        queue<int> que;
        for(int i = 1; i <= n; ++i){
            if(!L[i]){
                que.push(i);
                dist[i] = 0;
            }
            else dist[i] = -1;
        }

        bool augpath = false;
        while(!que.empty()){
            int u = que.front(); que.pop();
            for(int v: adj[u]){
                if(!R[v]){
                    augpath = true;
                }
                else if(dist[R[v]] < 0){
                    dist[R[v]] = dist[u] + 1;
                    que.push(R[v]);
                }
            }
        }

        return augpath;
    }

    bool dfs(int u){
        for(int v: adj[u]){
            if(R[v] == 0 || (dist[R[v]] == dist[u] + 1 && dfs(R[v]))){
                L[u] = v;
                R[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching(){
        int res = 0;
        while(bfs()){
            for(int u = 1; u <= n; ++u){
                if(L[u] == 0 && dfs(u)){
                    ++res;
                }
            }
        }

        return res;
    }

    vector<pair<int, int>> getMatching(){
        vector<pair<int, int>> matching;
        for(int i = 1; i <= n; ++i){
            if(L[i] != 0){
                matching.emplace_back(i, L[i]);
            }
        }
        return matching;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int L, R, M;
    cin >> L >> R >> M;

    Hopcroft_Karp HK(L, R);
    for(int i = 1; i <= M; ++i){
        int a, b;
        cin >> a >> b;

        HK.add_edge(a + 1, b + 1);
    }

    int res = HK.maxMatching();
    cout << res << '\n';
    for(const pair<int, int>& e: HK.getMatching()){
        cout << e.first - 1 << ' ' << e.second - 1 << '\n';
    }

    return 0;
}
