/******************************************************************************
Link: https://judge.yosupo.jp/problem/cycle_detection
Code: cycle_detection
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-10-16.25.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
vector<pair<int, int>> adj[MAXN + 5];
int n, m;

vector<int> cycle;
int mark[MAXN + 5];
bool dfs(int u){
    mark[u] = 1;
    for(const pair<int, int>& e: adj[u]){
        int v, idx; tie(v, idx) = e;
        if(mark[v] == 0){
            if(dfs(v)){
                cycle.push_back(idx);
                return true;
            }
        }
        else if(mark[v] == 1){
            cycle.push_back(idx);
            return true;
        }
    }
    mark[u] = 2;

    return false;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i - 1});
    }

    for(int u = 0; u < n; ++u){
        if(mark[u] == 0 && dfs(u)){
            cout << cycle.size() << "\n";
            reverse(begin(cycle), end(cycle));
            for(int x: cycle) cout << x << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
