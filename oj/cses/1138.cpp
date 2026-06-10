#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int h[MAXN + 5],
    sz[MAXN + 5],
    par[MAXN + 5],

    ChainHead[MAXN + 5],
    ChainID[MAXN + 5],
    Pos[MAXN + 5],
    Arr[MAXN + 5],
    CntChains = 1, CurPos;

vector<int> adj[MAXN + 5];
int n;

void dfs(int u, int prev){
    sz[u] = 1;
    for(int v: adj[u]){
        if(v == prev) continue;

        par[v] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int prev){
    if(!ChainHead[CntChains]) ChainHead[CntChains] = u;
    ChainID[u] = CntChains;

    ++CurPos;
    Pos[u] = CurPos;
    Arr[CurPos] = u;

    int nxt = 0;
    for(int v: adj[u]){
        if(v == prev) continue;

        if(nxt == 0 || sz[nxt] < sz[v]) nxt = v;
    }
    if(nxt) hld(nxt, u);

    for(int v: adj[u]){
        if(v == prev || v == nxt) continue;
        
        ++CntChains;
        hld(v, u);
    }
}

int nodes[MAXN * 4 + 5];
int Val[MAXN + 5];
void build(int id, int l, int r){
    if(l == r){
        nodes[id] = Val[Arr[l]];
        return;
    }

    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

void update(int id, int l, int r, int idx, int val){
    if(r < idx || idx < l) return;
    if(l == r){
        nodes[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, idx, val);
    update(id << 1 | 1, mid + 1, r, idx, val);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id];

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> Val[i];
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 0);
    build(1, 1, n);
    
    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int s, x;
            cin >> s >> x;

            update(1, 1, n, Pos[s], x);
        }
        else{
            int s;
            cin >> s;

            int ans = 0;
            while(ChainID[1] != ChainID[s]){
                ans += get(1, 1, n, Pos[ChainHead[ChainID[s]]], Pos[s]);
                s = par[ChainHead[ChainID[s]]];
            }
            ans += get(1, 1, n, Pos[1], Pos[s]);

            cout << ans << '\n';
        }
    }

    return 0;
}