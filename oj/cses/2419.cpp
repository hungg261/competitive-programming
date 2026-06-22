/******************************************************************************
Link: https://cses.fi/problemset/task/2419
Code: 2419
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-17-17.49.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, a[MAXN + 5];

int solve(int b){
    int res = 0;
    for(int i = 0; i < n; ++i){
        if((a[i] >> b & 1) && ((n - 1) & i) == i) res ^= 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int res = 0;
    for(int b = 0; b < 31; ++b){
        res |= solve(b) << b;
    }

    cout << res << "\n";

    return 0;
}
