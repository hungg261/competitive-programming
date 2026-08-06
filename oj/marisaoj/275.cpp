/******************************************************************************
Link: https://marisaoj.com/problem/275
Code: 275
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-06-10.19.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
vector<int> adj[MAXN + 5];
int sz[MAXN + 5];

void dfs_compute(int u, int prv){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prv) continue;
        dfs_compute(v, u);

        sz[u] = max(sz[u], sz[v] + 1);
    }
}

int n, k;

namespace Brute{

int res = 0;
vector<int> dfs(int u, int prv){
    vector<int> freq = {1};
    for(int v: adj[u]){
        if(v == prv) continue;

        vector<int> child = dfs(v, u);
        int sz_u = freq.size(), sz_v = child.size();

        for(int dv = 0; dv < sz_v; ++dv){
            int du = k - (dv + 1);
            if(du >= sz_u) continue;
            else if(du < 0) break;

            res += freq[du] * child[dv];
        }

        freq.resize(max(sz_u, sz_v + 1), 0);
        for(int dv = 0; dv < sz_v; ++dv){
            freq[dv + 1] += child[dv];
        }
    }

    return freq;
}

void solve(){
    dfs(1, -1);
    cout << res << "\n";
}

}

namespace Solve{

map<int, int> cnt[MAXN + 5];
int res = 0;
void dfs(int u = 1, int prv = -1, int d = 0){
    cnt[u][d] = 1;

    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u, d + 1);

        if(cnt[v].size() > cnt[u].size()){
            swap(cnt[u], cnt[v]);
        }

        for(const pair<int, int>& p: cnt[v]){
            int dv, c; tie(dv, c) = p;

            int du = k + d * 2 - dv;
            if(cnt[u].count(du)) res += cnt[u][du] * c;
        }

        for(const pair<int, int>& p: cnt[v]){
            int dv, c; tie(dv, c) = p;
            cnt[u][dv] += c;
        }
        cnt[v].clear();
    }
}

void solve(){
    dfs();
    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int a = i, b = i + 1;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solve::solve();

    return 0;
}
