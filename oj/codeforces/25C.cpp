/******************************************************************************
Link: https://codeforces.com/contest/25/problem/C
Code: 25C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-28-16.43.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300;
int n;
int f[MAXN + 5][MAXN + 5];

long long eval(){
    long long res = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            res += f[i][j];
        }
    }

    return res;
}

void add_edge(int a, int b, int c){
    f[a][b] = f[b][a] = min(f[a][b], c);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            f[i][j] = min({
                          f[i][j],
                          f[i][a] + c + f[b][j],
                          f[i][b] + c + f[a][j]
                          });
        }
    }
}

void compute(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> f[i][j];
        }
    }

    compute();

    int q;
    cin >> q;

    while(q--){
        int a, b, c;
        cin >> a >> b >> c;

        add_edge(a, b, c);

        cout << eval() << " ";
    }

    return 0;
}
