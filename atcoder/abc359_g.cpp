/******************************************************************************
Link: https://atcoder.jp/contests/abc359/tasks/abc359_g
Code: abc359_g
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-07.50.48
*******************************************************************************/
#include<bits/stdc++.h>
//#define cerr if(false)cerr
using namespace std;

const int MAXN = 2e5, MAXLG = __lg(MAXN) + 1;
int n;
vector<int> queries[MAXN + 5];

vector<int> adj[MAXN + 5];
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
int tin[MAXN + 5], tout[MAXN + 5], Timer = 0;

void dfs(int u, int prv){
    tin[u] = ++Timer;
    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        table[v][0] = u;
        dfs(v, u);
    }

    tout[u] = Timer;
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int lift(int pos, int steps){
    for(int bit = MAXLG; bit >= 0; --bit){
        if(steps >> bit & 1) pos = table[pos][bit];
    }
    return pos;
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    v = lift(v, h[v] - h[u]);

    if(u == v) return u;

    for(int bit = MAXLG; bit >= 0; --bit){
        if(table[u][bit] != table[v][bit]){
            u = table[u][bit];
            v = table[v][bit];
        }
    }

    return table[u][0];
}

bool in_subtree(int v, int u){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int find_dist(int u, int v){
    return h[u] + h[v] - 2 * h[find_lca(u, v)];
}

void debug(int sz);

vector<pair<int, int>> subtree[MAXN + 5];

int dfs_solve(int u, int prv, int above, int k, int& res, const vector<int>& temp){
    int down = 0;

    if(binary_search(begin(temp), end(temp), u)){
        ++above;
        ++down;
    }

    for(const pair<int, int>& p: subtree[u]){
        int v, w; tie(v, w) = p;
        if(v == prv) continue;

        int below = dfs_solve(v, u, above, k, res, temp);
        res += above * below * w;

        cerr << "\t" << u << ' ' << v << ' ' << w << ' ' << above << ' ' << below << '\n';

        down += below;
    }

    return down;
}

int ans = 0;
void solve(int q){
    vector<int> arr = queries[q];
    if(arr.empty()) return;

    int k = arr.size();

    sort(begin(arr), end(arr), [](int x, int y){ return tin[x] < tin[y]; });
    for(int i = 0; i < k - 1; ++i){
        arr.push_back(find_lca(arr[i], arr[i + 1]));
    }

    sort(begin(arr), end(arr));
    arr.erase(unique(begin(arr), end(arr)), end(arr));
    vector<int> temp = arr;

    sort(begin(arr), end(arr), [](int x, int y){ return tin[x] < tin[y]; });
    k = arr.size();

    vector<int> sta = {arr[0]};
    for(int i = 1; i < k; ++i){
        while(!in_subtree(arr[i], sta.back())) sta.pop_back();

        int u = sta.back(), v = arr[i],
            d = find_dist(u, v);
        subtree[u].emplace_back(v, d);
        subtree[v].emplace_back(u, d);

        sta.push_back(arr[i]);
    }

    cerr << "----------\n";
    for(int u: arr){
        for(const pair<int, int>& p: subtree[u]){
            int v, w; tie(v, w) = p;
            if(u <= v) cerr << u << ' ' << v << ' ' << w << '\n';
        }
    }

    int res = 0;
    dfs_solve(arr[0], -1, 0, k, res, temp);

    cerr << res << '\n';

    cerr << "----- nxt -----\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    compute();

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        queries[cur].push_back(i);
    }
    for(int k = 1; k <= n; ++k){
        solve(k);
    }

    cout << ans << '\n';

    return 0;
}
