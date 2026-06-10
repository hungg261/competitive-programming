/******************************************************************************
Link: https://codeforces.com/problemset/problem/1811/C
Code: 1811C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-13-09.30.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1, 1e9 + 5), b(n);
    for(int i = 1; i < n; ++i)
        cin >> b[i];

    for(int i = 1; i < n; ++i){
        a[i] = min(a[i], b[i]);
        a[i + 1] = min(a[i + 1], b[i]);
    }

    for(int i = 1; i <= n; ++i){
        cout << a[i] << ' ';
    }
    cout << '\n';
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
