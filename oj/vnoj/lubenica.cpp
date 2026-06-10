#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAXN = 1e5;
int par[MAXN + 5],
    h[MAXN + 5],
    sz[MAXN + 5],
 
    ChainHead[MAXN + 5],
    ChainID[MAXN + 5],
    Arr[MAXN + 5],
    Pos[MAXN + 5],
    curChain = 1, curPos = 0;
 
vector<pair<int, int>> adj[MAXN + 5];
int n, values[MAXN + 5];
 
void dfs(int u, int prev){
    sz[u] = 1;
    for(const pair<int, int>& p: adj[u]){
        int v, w; tie(v, w) = p;
        if(v == prev) continue;
 
        h[v] = h[u] + 1;
        par[v] = u;
        values[v] = w;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
void Hld(int u, int prev){
    if(!ChainHead[curChain]) ChainHead[curChain] = u;
    ChainID[u] = curChain;
 
    Arr[++curPos] = u;
    Pos[u] = curPos;
 
    int nxt = -1;
    for(const pair<int, int>& p: adj[u]){
        int v = p.first;
        if(v == prev) continue;
 
        if(nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if(nxt != -1) Hld(nxt, u);
 
    for(const pair<int, int>& p: adj[u]){
        int v = p.first;
        if(v == prev || v == nxt) continue;
 
        ++curChain;
        Hld(v, u);
    }
}
 
pair<int, int> nodes[MAXN * 4 + 5];
void build(int id, int l, int r){
    if(l == r){
        if(l == 1){
            nodes[id] = {1e9, -1e9};
            return;
        }
 
        nodes[id] = {values[Arr[l]], values[Arr[l]]};
        return;
    }
 
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id].first = min(nodes[id << 1].first, nodes[id << 1 | 1].first);
    nodes[id].second = max(nodes[id << 1].second, nodes[id << 1 | 1].second);
}
 
pair<int, int> get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return make_pair(1e9, -1e9);
    if(u <= l && r <= v) return nodes[id];
 
    int mid = (l + r) >> 1;
    pair<int, int> L = get(id << 1, l, mid, u, v), 
                    R = get(id << 1 | 1, mid + 1, r, u, v);
    return {min(L.first, R.first), max(L.second, R.second)};
}
 
void query(int u, int v){
    int ans1 = 1e9, ans2 = -1e9;
    while(ChainID[u] != ChainID[v]){
        if(ChainID[u] > ChainID[v]){
            pair<int, int> res = get(1, 1, n, Pos[ChainHead[ChainID[u]]], Pos[u]);
            ans1 = min(ans1, res.first);
            ans2 = max(ans2, res.second);
 
            u = par[ChainHead[ChainID[u]]];
        }
        else{
            pair<int, int> res = get(1, 1, n, Pos[ChainHead[ChainID[v]]], Pos[v]);
            ans1 = min(ans1, res.first);
            ans2 = max(ans2, res.second);
 
            v = par[ChainHead[ChainID[v]]];
        }
    }
    if(h[u] > h[v]) swap(u, v);
 
    pair<int, int> res = get(1, 1, n, Pos[u] + 1, Pos[v]);
    ans1 = min(ans1, res.first);
    ans2 = max(ans2, res.second);
 
    cout << ans1 << ' ' << ans2 << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
 
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
 
    dfs(1, 0);
    Hld(1, 0);
    build(1, 1, n);
 
    int q;
    cin >> q;
 
    while(q--){
        int u, v;
        cin >> u >> v;
 
        query(u, v);
    }
 
    return 0;
}
