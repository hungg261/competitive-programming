/******************************************************************************
Link: https://codeforces.com/contest/2283/problem/D
Code: 2283D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-04-22.48.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }

    void link(int a, int b){
        par[find(a)] = find(b);
    }
};

int n, MAXLG;
vector<vector<int>> adj, up;
vector<int> h, par;

void compute(){
    h.assign(n + 1, 0);
    par.assign(n + 1, 0);
    h[0] = -1;

    vector<int> st;
    st.push_back(1);
    while(!st.empty()){
        int u = st.back();
        st.pop_back();
        for(int v: adj[u]){
            if(v == par[u]) continue;
            par[v] = u;
            h[v] = h[u] + 1;
            st.push_back(v);
        }
    }

    MAXLG = 1;
    while((1 << MAXLG) <= n) ++MAXLG;

    up.assign(MAXLG, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i) up[0][i] = par[i];
    for(int j = 1; j < MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }
}

int find_lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int diff = h[u] - h[v];
    for(int j = 0; j < MAXLG; ++j){
        if((diff >> j) & 1) u = up[j][u];
    }
    if(u == v) return u;
    for(int j = MAXLG - 1; j >= 0; --j){
        if(up[j][u] != up[j][v]){
            u = up[j][u];
            v = up[j][v];
        }
    }
    return up[0][u];
}

int getBlack(int k){
    int L = max(1, k - n);
    int R = min(n, k - 1);
    int res = R - L + 1;
    if(k % 2 == 0){
        int mid = k / 2;
        if(L <= mid && mid <= R) --res;
    }
    return res;
}

int getGray(int k){
    DSU dsu(n);
    dsu.init();

    int L = max(1, k - n);
    int R = min(n, k - 1);
    int mid = (k % 2 == 0) ? k / 2 : -1;

    for(int v = L; v <= R; ++v){
        if(v == mid) continue;
        dsu.link(v, par[v]);
    }

    int gray = 0;

    for(int a = L; a <= min(R, (k - 1) / 2); ++a){
        int b = k - a;
        int c = find_lca(a, b);

        int x = dsu.find(a);
        while(h[x] > h[c]){
            ++gray;
            dsu.link(x, par[x]);
            x = dsu.find(x);
        }

        x = dsu.find(b);
        while(h[x] > h[c]){
            ++gray;
            dsu.link(x, par[x]);
            x = dsu.find(x);
        }

        if(dsu.find(c) == c){
            ++gray;
            dsu.link(c, par[c]);
        }
    }

    return gray;
}

void solve(){
    cin >> n;

    adj.assign(n + 1, {});
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    compute();

    vector<int> cand;
    if(n % 2 == 0){
        cand.push_back(n + 1);
    }
    else{
        cand.push_back(n);
        cand.push_back(n + 1);
        cand.push_back(n + 2);
    }

    int ans = -1, bestBlack = -1, bestGray = -1;
    for(int k: cand){
        int black = getBlack(k);
        int gray = getGray(k);
        if(black > bestBlack || (black == bestBlack && gray > bestGray)){
            bestBlack = black;
            bestGray = gray;
            ans = k;
        }
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
