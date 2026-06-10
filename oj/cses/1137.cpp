/******************************************************************************
Link: https://cses.fi/problemset/task/1137
Code: 1137
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-28-11.54.32
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz): n(sz){
        BIT.resize(sz + 1, 0);
    }

    void update(int idx, int val){
        for(int i = idx; i <= n; i += i & -i) BIT[i] += val;
    }

    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i & -i) res += BIT[i];
        return res;
    }
    int get(int l, int r){ return get(r) - get(l - 1); }
};

const int MAXN = 2e5;
int st[MAXN + 5], en[MAXN + 5], tour[MAXN + 5];
vector<int> adj[MAXN + 5];
int arr[MAXN + 5], n, m;

void dfs(int u, int prev){
    tour[++m] = u;
    st[u] = m;

    for(int v: adj[u]){
        if(v == prev) continue;

        dfs(v, u);
    }

    en[u] = m;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1137.INP","r",stdin);
    //freopen("1137.OUT","w",stdout);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    FenwickTree fwt(n);
    for(int i = 1; i <= n; ++i){
        fwt.update(st[i], arr[i]);
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int s, x;
            cin >> s >> x;

            fwt.update(st[s], x - fwt.get(st[s], st[s]));
        }
        else{
            int s;
            cin >> s;

            cout << fwt.get(st[s], en[s]) << '\n';
        }
    }

    return 0;
}
