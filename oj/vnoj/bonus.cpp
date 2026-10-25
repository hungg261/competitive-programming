/******************************************************************************
Link: https://oj.vnoi.info/problem/bonus
Code: bonus
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-21.59.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, k, a[MAXN + 5][MAXN + 5];
int P[MAXN + 5][MAXN + 5];

void compute(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + a[i][j];
        }
    }
}

int get(int x1, int y1, int x2, int y2){
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    compute();

    int res = 0;
    for(int i = k; i <= n; ++i){
        for(int j = k; j <= n; ++j){
            res = max(res, get(i - k + 1, j - k + 1, i, j));
        }
    }

    cout << res << "\n";

    return 0;
}
