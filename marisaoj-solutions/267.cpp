/******************************************************************************
Link: https://marisaoj.com/problem/267
Code: 267
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-10-19.22.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, MAXLG = __lg(MAXN);
int table[MAXN + 5][MAXLG + 5], n, q;
int pre[MAXN + 5], pre2[MAXN + 5];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int find_min(int l, int r){
    int bit = __lg(r - l + 1);
    return min(table[l][bit], table[r - (1 << bit) + 1][bit]);
}

int f(int l, int len){
    int r = l + len - 1;
    return (l + r) * (r - l + 1) / 2;
}

int f2(int l, int len){
    int r = l + len - 1;
    return r * (r + 1) * (r * 2 + 1) / 6 - l * (l - 1) * (l * 2 - 1) / 6;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> table[i][0];
        pre[i] = pre[i - 1] + table[i][0];
        pre2[i] = pre2[i - 1] + table[i][0] * table[i][0];
    }

    compute();

    while(q--){
        int l, r;
        cin >> l >> r;

        int len = r - l + 1,
            mn = find_min(l, r);
        bool ok1 = f(mn, len) == pre[r] - pre[l - 1],
            ok2 = f2(mn, len) == pre2[r] - pre2[l - 1];

        cout << (ok1 && ok2 ? "YES\n" : "NO\n");
    }

    return 0;
}
