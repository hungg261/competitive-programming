/******************************************************************************
Link: https://oj.vnoi.info/problem/vr_dst_treevalue
Code: vr_dst_treevalue
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-20-14.13.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 1e5;
int n, a[MAXN + 5];
vector<int> adj[MAXN + 5];
FenwickTree fwt;

int ans[MAXN + 5];
void dfs(int u = 1, int prv = -1){
    ans[u] = fwt.get(a[u] + 1, fwt.n);
    fwt.update(a[u], 1);

    for(int v: adj[u]){
        if(v == prv) continue;
        dfs(v, u);
    }

    fwt.update(a[u], -1);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<int> values;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        values.push_back(a[i]);
    }
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(begin(values), end(values), a[i]) - begin(values) + 1;
    }

    fwt = FenwickTree(values.size() + 5);
    dfs();

    for(int u = 1; u <= n; ++u){
        cout << ans[u] << " ";
    }

    return 0;
}
