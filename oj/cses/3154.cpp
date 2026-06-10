/******************************************************************************
Link: https://cses.fi/problemset/task/3154
Code: 3154
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-26-11.00.20
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int powmod(int a, int b, int m = MOD){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

const int MAXN = 500, MAXM = 500;
int a[MAXN + 5][MAXM + 1 + 5], n, m;
int x[MAXN + 5];
void gauss(){
    int row = 0, col = 0;
    while(row < n && col < m){
        int sw = -1;
        for(int i = row; i < n; ++i){
            if(a[i][col] != 0){
                sw = i;
                break;
            }
        }

        if(sw == -1){
            ++col;
            continue;
        }
        for(int j = 0; j <= m; ++j) swap(a[row][j], a[sw][j]);

        int inv = powmod(a[row][col], MOD - 2, MOD);
        for(int j = col; j <= m; ++j)
            a[row][j] = a[row][j] * inv % MOD;

        for(int i = 0; i < n; ++i){
            if(i == row || a[i][col] == 0) continue;

            int mul = a[i][col];
            for(int j = col; j <= m; ++j){
                a[i][j] -= mul * a[row][j] % MOD;
                a[i][j] = (a[i][j] + MOD) % MOD;
            }
        }

        ++row;
        ++col;
    }

    cerr << '\n';
    for(int j = m - 1; j >= 0; --j){
        x[j] = a[j][m];
        for(int co = j + 1; co < m; ++co)
            x[j] = (x[j] - a[j][co] * x[co] % MOD + MOD) % MOD;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= m; ++j){
            cerr << a[i][j] << ' ';
        }
        cerr << '\n';
    }
    for(int j = 0; j < m; ++j) cerr << x[j] << ' '; cerr << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    gauss();

    return 0;
}
