#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 100;
int n, m, k, dp[MAXN + 5][MAXN + 5];
int mid[MAXN + 5][MAXN + 5];

const int INF = 1e18;
void prepare(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            mid[i][j] = i;
            dp[i][j] = i == j ? 0 : INF;
        }
    }
}

void compute(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int cur = dp[i][k] + dp[k][j];
                if(cur < dp[i][j]){
                    mid[i][j] = k;
                    dp[i][j] = cur;
                }
            }
        }
    }
}

void trace(int u, int v, vector<int>& res){
    if(u == v) return;
    
    if(mid[u][v] == u){
        res.push_back(v);
        return;
    }
    
    trace(u, mid[u][v], res);
    trace(mid[u][v], v, res);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    
    prepare();
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        
        dp[a][b] = dp[b][a] = min(dp[a][b], c);
    }
    
    compute();
    
    while(k--){
        int type, u, v; cin >> type >> u >> v;
        
        if(type == 0){
            cout << dp[u][v] << '\n';
        }
        else{
            vector<int> path = {u};
            trace(u, v, path);
            
            cout << path.size() << ' ';
            for(int node: path) cout << node << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}
