/******************************************************************************
Link: https://judge.yosupo.jp/problem/static_range_sum
Code: static_range_sum
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-12-16.45.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5, MAXLG = __lg(MAXN) + 1;
int N, Q;
int table[MAXN + 5][MAXLG + 5];

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 0; i + (1 << j) - 1 < N; ++i){
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
        }
    }
}

int get(int l, int r){
    int len = r - l;
    int res = 0;
    for(int b = MAXLG; b >= 0; --b){
        if(len >> b & 1){
            res += table[l][b];
            l += 1 << b;
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for(int i = 0; i < N; ++i){
        cin >> table[i][0];
    }

    compute();

    while(Q--){
        int l, r;
        cin >> l >> r;

        cout << get(l, r) << "\n";
    }

    return 0;
}
