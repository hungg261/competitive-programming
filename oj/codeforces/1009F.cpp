/******************************************************************************
Link: https://codeforces.com/contest/1009/problem/F
Code: 1009F
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-17.29.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n;
vector<int> adj[MAXN + 5];

int d[MAXN + 5];
int dfs_compute(int u = 1, int prv = -1){
    d[u] = 0;
    for(int v: adj[u]){
        if(v == prv) continue;
        d[u] = max(d[u], dfs_compute(v, u) + 1);
    }
    return d[u];
}

int ans[MAXN + 5];
vector<int> dfs(int u = 1, int prv = -1){
    int nxt = -1;
    for(int v: adj[u]){
        if(v == prv) continue;
        if(nxt == -1 || d[v] > d[nxt]) nxt = v;
    }

    vector<int> cnt;
    if(nxt != -1){
        cnt = dfs(nxt, u);
        ans[u] = ans[nxt] + 1;
    }

    cnt.push_back(1);
    int total = cnt.size();

    if(1 >= cnt[total - 1 - ans[u]]){
        ans[u] = 0;
    }

    for(int v: adj[u]){
        if(v == prv || v == nxt) continue;
        vector<int> child = dfs(v, u);

        int sz = child.size();
        for(int l = 0; l < sz; ++l){
            int fu = l + 1;
            cnt[total - 1 - fu] += child[sz - 1 - l];

            int curCnt = cnt[total - 1 - fu];
            int maxCnt = cnt[total - 1 - ans[u]];

            if(curCnt > maxCnt){
                ans[u] = fu;
            }
            else if(curCnt == maxCnt && fu < ans[u]) {
                ans[u] = fu;
            }
        }
    }

    return cnt;
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

    dfs_compute();

    vector<int> cnt = dfs();
    int res = max_element(begin(cnt), end(cnt)) - begin(cnt);

    for(int u = 1; u <= n; ++u){
        cout << ans[u] << "\n";
    }

    return 0;
}
