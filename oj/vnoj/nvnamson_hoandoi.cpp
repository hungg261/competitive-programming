/******************************************************************************
Link: https://oj.vnoi.info/problem/nvnamson_hoandoi
Code: nvnamson_hoandoi
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-02-23.02.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    int max_a = -1, max_b = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] < b[i]) swap(a[i], b[i]);
        max_a = max(max_a, a[i]);
        max_b = max(max_b, b[i]);
    }

    cout << max_a * max_b << "\n";
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
