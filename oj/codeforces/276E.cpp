#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        ++idx;
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        ++idx;
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    void update(int l, int r, int x){
        l = max(0ll, l); r = min(n, r);
        if(l > r) return;

        update(l, x);
        update(r + 1, -x);
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 1e5;
int n, q;
vector<int> adj[MAXN + 5];

int h[MAXN + 5], maxH[MAXN + 5];
int ChainID[MAXN + 5], ChainSz[MAXN + 5],
    curChain = 0, curPos = 0;
void dfs(int u, int prv){
    ChainID[u] = curChain;
    ChainSz[curChain]++;

    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

FenwickTree glob, fwt[MAXN + 5];

void add(int u, int x, int d){
    if(u == 1){
        glob.update(0, d, x);
        return;
    }

    if(d >= h[u]){
        glob.update(0, d - h[u], x);
        fwt[ChainID[u]].update(-h[u] + d + 1, h[u] + d, x);
        return;
    }

    fwt[ChainID[u]].update(h[u] - d, h[u] + d, x);
}

int get(int u){
    return fwt[ChainID[u]].get(h[u]) + glob.get(h[u]);
}

void solve(){
    for(int id = 0; id <= curChain; ++id){
        fwt[id] = FenwickTree(ChainSz[id] + 5);
    }
    glob = FenwickTree(n + 5);

    while(q--){
        int type;
        cin >> type;

        if(type == 0){
            int u, x, d;
            cin >> u >> x >> d;

            add(u, x, d);
        }
        else{
            int u;
            cin >> u;

            cout << get(u) << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int v: adj[1]){
        ++curChain;
        h[v] = h[1] + 1;
        dfs(v, 1);
    }

    for(int u = 1; u <= n; ++u){
        maxH[u] = ChainSz[ChainID[u]];
    }

    solve();

    return 0;
}
