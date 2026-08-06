/******************************************************************************
Link: https://marisaoj.com/problem/275
Code: 275
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-06-14.34.07
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

int res = 0;
vector<int> dfs(int u = 1, int prv = -1){
    vector<int> freq = {1};

    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }

    if(nxt != -1){
        vector<int> big = dfs(nxt, u);
        swap(big, freq);
        freq.insert(freq.begin(), 1);

        if(k < (int)freq.size()) res += freq[k];
    }

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;

        vector<int> small = dfs(v, u);

        for(int dv = 0; dv < (int)small.size(); ++dv){
            int du = k - (dv + 1);
            if(du >= (int)freq.size()) continue;
            else if(du < 0) break;

            res += freq[du] * small[dv];
        }

        if(freq.size() < small.size() + 1)
            freq.resize(small.size() + 1, 0);

        for(int dv = 0; dv < (int)small.size(); ++dv){
            freq[dv + 1] += small[dv];
        }
    }

    return freq;
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
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solve::solve();

    return 0;
}
