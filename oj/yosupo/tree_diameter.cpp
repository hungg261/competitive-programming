/******************************************************************************
Link: https://judge.yosupo.jp/problem/tree_diameter
Code: tree_diameter
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-11-08.06.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int n;
vector<pair<int, int>> adj[MAXN + 5];

vector<int> path;
bool dfs_path(int u, int prv, int t){
    if(u == t){
        path.push_back(u);
        return true;
    }

    for(const pair<int, int>& e: adj[u]){
        int v, w; tie(v, w) = e;
        if(v == prv) continue;

        if(dfs_path(v, u, t)){
            path.push_back(u);
            return true;
        }
    }

    return false;
}

pair<long long, int> dfs_farthest(int u, int prv){
    pair<long long, int> best = {0LL, u};
    for(const pair<int, int>& e: adj[u]){
        int v, w; tie(v, w) = e;
        if(v == prv) continue;

        long long cost; int tar; tie(cost, tar) = dfs_farthest(v, u);
        best = max(best, {cost + w, tar});
    }

    return best;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int x, y; long long s;

    x = dfs_farthest(1, -1).second;
    tie(s, y) = dfs_farthest(x, -1);

    dfs_path(x, -1, y);

    cout << s << " " << (int)path.size() << "\n";

    reverse(begin(path), end(path));
    for(int u: path) cout << u << " ";
    cout << "\n";

    return 0;
}
