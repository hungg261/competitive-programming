/******************************************************************************
Link: https://codeforces.com/contest/463/problem/D
Code: 463D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-13-18.23.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<int> adj[MAXN + 5];
int dp[MAXN + 5];

vector<int> topo;
bool mark[MAXN + 5];
void toposort(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        toposort(v);
    }

    topo.push_back(u);
}

void solve(){
    for(int u = 1; u <= MAXN; ++u){
        toposort(u);
        dp[u] = 1;
    }

    reverse(begin(topo), end(topo));
    for(int u: topo){
        for(int v: adj[u]){
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    cout << *max_element(dp + 1, dp + MAXN + 1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(k, vector<int>(n));
    vector<vector<int>> nodes(n + 1, vector<int>(k));
    for(int j = 0; j < k; ++j){
        for(int i = 0; i < n; ++i){
            cin >> arr[j][i];
            nodes[arr[j][i]][j] = i;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int q = 0; q < k; ++q){
                if(nodes[i][q] <= nodes[j][q]){
                    goto nxt;
                }
            }

            adj[j].push_back(i);
            nxt:;
        }
    }

    solve();

    return 0;
}
