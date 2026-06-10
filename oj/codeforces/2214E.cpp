/******************************************************************************
Link: https://codeforces.com/contest/2214/problem/E
Code: 2214E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-01-22.33.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int f[101][101];

void solve(){
    int n, m;
    cin >> n >> m;

    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        f[a][b] = c;
        f[b][a] = c;
    }

    for(int i = 1; i <= n; ++i){
        for(int k = 1; k <= n; ++k){
            for(int j = 1; j <= n; ++j){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    for(int i = 2; i <= n; ++i){
        cout << (f[1][i] == f[0][0] ? -1 : f[1][i]) << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
