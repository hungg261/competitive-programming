/******************************************************************************
Link: https://codeforces.com/contest/1458/problem/A
Code: 1458A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-11.13.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, m;
int a[MAXN + 5], b[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    int g = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(i > 1) g = __gcd(g, a[i] - a[1]);
    }
    for(int i = 1; i <= m; ++i) cin >> b[i];

    for(int j = 1; j <= m; ++j){
        cout << llabs(__gcd(a[1] + b[j], g)) << ' ';
    }

    return 0;
}
