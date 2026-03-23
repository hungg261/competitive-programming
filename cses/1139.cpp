/******************************************************************************
Link: https://cses.fi/problemset/task/1139
Code: 1139
Time (YYYY-MM-DD-hh.mm.ss): 2025-09-28-00.23.53
*******************************************************************************/
#include<bits/stdc++.h>
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
int arr[MAXN + 5],
    st[MAXN + 5], en[MAXN + 5], tour[MAXN + 5];
vector<int> adj[MAXN + 5];
int n, m;

int temp[MAXN + 5];
void compress(){
    for(int i = 1; i <= n; ++i) temp[i] = arr[i];
    sort(temp + 1, temp + n + 1);

    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(temp + 1, temp + n + 1, arr[i]) - temp;
    }
}

void dfs(int u, int prev){
    tour[++m] = u;
    st[u] = m;

    for(int v: adj[u]){
        if(v == prev) continue;

        dfs(v, u);
    }

    en[u] = m;
}

vector<pair<int, int>> queries[MAXN + 5];
int mp[MAXN + 5];
void solve(){
    FenwickTree fwt(n);
    vector<int> res(n + 1);
    for(int i = n; i >= 1; --i){
        int val = arr[tour[i]];

        if(mp[val]) fwt.update(mp[val], -1);
        mp[val] = i;
        fwt.update(i, 1);

        for(const pair<int, int>& qr: queries[i]){
            res[qr.second] = fwt.get(qr.first);
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1139.INP","r",stdin);
    //freopen("1139.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    compress();

    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; ++i){
        queries[st[i]].push_back({en[i], i});
    }
    solve();

    return 0;
}
