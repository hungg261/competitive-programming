/******************************************************************************
Link: https://codeforces.com/contest/2277/problem/B
Code: 2277B
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-18.43.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    if(*min_element(begin(a), end(a)) < n){
        cout << n << "\n";
    }
    else cout << "0\n";
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
