#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;
int n, m;
vector<vector<int>> adj;

int mark[MAXN + 5];
vector<int> res;
int dfs(int u){
    mark[u] = 1;

    for(int v: adj[u]){
        if(mark[v] == 1){
            res.push_back(v);
            mark[u] = 2;
            return v;
        }
        else if(mark[v] == 2){
            continue;
        }

        int nxt = dfs(v);
        if(nxt != -1){
            res.push_back(v);
            mark[u] = 2;
            return v;
        }
    }

    mark[u] = 2;
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);

    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i){
        if(dfs(i) != -1){
            res.push_back(i);

            vector<int> cnt(n + 1, 0);
            int last = -1;
            for(int u: res){
                ++cnt[u];
                if(cnt[u] > 1){
                    last = u;
                    break;
                }
            }

            reverse(begin(res), end(res));
            res = vector<int>(find(begin(res), end(res), last), end(res));

            cout << res.size() << '\n';
            for(int node: res) cout << node << ' '; cout << '\n';
            return 0;
        }
        res.clear();
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
