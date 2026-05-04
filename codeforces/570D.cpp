/******************************************************************************
Link: https://codeforces.com/contest/570/problem/D
Code: 570D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-04-17.09.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Data{
    int tin, mask;

    Data() = default;
    Data(int _tin, int _mask = 0): tin(_tin), mask(_mask){}

    Data operator ^ (const Data& other) const {
        return Data(other.tin, mask ^ other.mask);
    }

    bool operator < (const Data& other) const {
        return tin < other.tin;
    }

    void debug() const {
        cerr << tin << "/" << mask << " ";
    }
};

const int MAXN = 5e5;
int n;
string c;

vector<int> adj[MAXN + 5];
vector<Data> pre[MAXN + 5];

int tin[MAXN + 5], tout[MAXN + 5], Timer = 0;

void dfs(int u, int prv = -1, int h = 1){
    tin[u] = ++Timer;

    pre[h].push_back(pre[h].back() ^ Data(Timer, 1 << c[u] - 'a'));

    for(int v: adj[u]){
        if(v == prv) continue;

        dfs(v, u, h + 1);
    }

    tout[u] = Timer;
}

void query(){
    int v, h;
    cin >> v >> h;

    int mask = prev(upper_bound(begin(pre[h]), end(pre[h]), Data(tout[v])))->mask
            ^ prev(lower_bound(begin(pre[h]), end(pre[h]), Data(tin[v])))->mask;

    cout << (!(mask & (mask - 1)) ? "Yes\n" : "No\n");
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> n >> q;
    for(int u = 2; u <= n; ++u){
        int v; cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> c;
    c = "#" + c;

    for(int h = 1; h <= n; ++h) pre[h].emplace_back(0);
    dfs(1);

    while(q--){
        query();
    }

    return 0;
}
