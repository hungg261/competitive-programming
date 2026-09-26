/******************************************************************************
Link: https://codeforces.com/contest/600/problem/E
Code: 600E
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-26-20.16.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, c[MAXN + 5];
vector<int> adj[MAXN + 5];

long long res[MAXN + 5];
pair<map<int, int>, pair<int, long long>> dfs(int u = 1, int prv = -1){
    map<int, int> mp;
    pair<int, long long> best;
    mp[c[u]]++;
    best = {1, c[u]};

    for(int v: adj[u]){
        if(v == prv) continue;

        map<int, int> child; pair<int, long long> child_best;
        tie(child, child_best) = dfs(v, u);

        if(mp.size() < child.size()){
            swap(mp, child);
            swap(best, child_best);
        }

        for(const pair<int, int>& p: child){
            int new_cnt = mp[p.first] += p.second;
            if(new_cnt > best.first){
                best = {new_cnt, p.first};
            }
            else if(new_cnt == best.first){
                best.second += p.first;
            }

        }
    }

    res[u] = best.second;
    return {move(mp), best};
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();

    for(int u = 1; u <= n; ++u){
        cout << res[u] << " ";
    }

    return 0;
}
