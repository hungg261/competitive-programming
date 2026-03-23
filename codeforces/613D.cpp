/******************************************************************************
Link: https://codeforces.com/problemset/problem/613/D
Code: 613D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-24-23.01.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n;
vector<int> adj[MAXN + 5];
int tin[MAXN + 5], tout[MAXN + 5], Timer = 0;

namespace LCA{

const int MAXLG = __lg(MAXN);
int h[MAXN + 5], table[MAXN + 5][MAXLG + 5];
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

void computeLCA(){
    dfs(1, -1);
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);
    {
        int diff = h[v] - h[u];
        for(int b = MAXLG; b >= 0; --b){
            if(diff >> b & 1) v = table[v][b];
        }
    }

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

int find_dist(int u, int v){
    return h[u] + h[v] - h[find_lca(u, v)] * 2;
}

bool isAncestor(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

}
using namespace LCA;


namespace Subsolve{

vector<int> subgraph[MAXN + 5];
bool important[MAXN + 5];

int Try(int u, int prv){
    int res = 0;
    if(!important[u]) ++res;

    for(int v: subgraph[u]){
        if(v == prv) continue;

        if(important[u] && important[v]) ++res;
        res += Try(v, u);
    }

    return res;
}

}
using namespace Subsolve;


namespace Solve{

void solve(){
    int k; cin >> k;

    vector<int> arr(k);
    for(int i = 0; i < k; ++i){
        cin >> arr[i];
        important[arr[i]] = true;
    }

    sort(begin(arr), end(arr), [&](int x, int y){
            return tin[x] < tin[y];
        });
    for(int i = 1; i < k; ++i)
        arr.push_back(find_lca(arr[i - 1], arr[i]));
    sort(begin(arr), end(arr), [&](int x, int y){
            return tin[x] < tin[y];
        });
    arr.erase(unique(begin(arr), end(arr)), end(arr));

    vector<int> sta = {arr[0]};
    for(int i = 1; i < (int)arr.size(); ++i){
        while(!sta.empty() && !isAncestor(sta.back(), arr[i]))
            sta.pop_back();

        int u = sta.back(), v = arr[i];
        if(important[u] && important[v] && find_dist(u, v) == 1){
            cout << "-1\n";
            return;
        }


        subgraph[u].push_back(v);
        subgraph[v].push_back(u);
        sta.push_back(arr[i]);
    }

    for(int ele: arr){
        subgraph[ele].clear();
        important[ele] = false;
    }
}

}
using namespace Solve;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    computeLCA();

    int q;
    cin >> q;

    while(q--){
        solve();
    }

//    cout << Try(1, -1) << '\n';

    return 0;
}
