/******************************************************************************
Link: https://codeforces.com/problemset/problem/2171/C1
Code: 2171C1
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-13-19.52.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    int idx = 0, x = 0;
    for(int i = 1; i <= n; ++i){
        x ^= a[i] ^ b[i];
        if(a[i] != b[i]) idx = i;
    }

    if(x == 0) cout << "Tie\n";
    else cout << (idx % 2 ? "Ajisai" : "Mai") << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
