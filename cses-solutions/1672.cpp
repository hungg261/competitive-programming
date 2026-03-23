#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;
const int INF32 = INT_MAX;
const long long INF64 = LLONG_MAX / 2;

int n, m, dist[MAXN + 1][MAXN + 1];
long long best[MAXN + 1][MAXN + 1];

void prepare(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dist[i][j] = INF32;
        }
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j){
                best[i][j] = 0;
            }
            else if(dist[i][j] != INF32){
                best[i][j] = dist[i][j];
            }
            else best[i][j] = INF64;
        }
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                best[i][j] = min(best[i][j], best[i][k] + best[k][j]);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> n >> m >> q;

    prepare();
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    solve();

    while(q--){
        int u, v;
        cin >> u >> v;

        cout << (best[u][v] == INF64 ? -1 : best[u][v]) << '\n';
    }

    return 0;
}
