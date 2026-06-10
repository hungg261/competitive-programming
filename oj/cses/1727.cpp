/******************************************************************************
Link: https://cses.fi/problemset/task/1727
Code: 1727
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-23-14.56.26
*******************************************************************************/
#include<bits/stdc++.h>
#define double long double
using namespace std;

const int MAXN = 100, MAXK = 100;
int n, k;

void solve(){
    double res = 0;
    for(int v = 1; v <= k; ++v){
        res += 1.0 - pow((double)(v - 1) / k, n);
    }

    cout << fixed << setprecision(6) << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1727.INP","r",stdin);
    //freopen("1727.OUT","w",stdout);
    cin >> n >> k;

    solve();

    return 0;
}
