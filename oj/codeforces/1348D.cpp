/******************************************************************************
Link: https://codeforces.com/contest/1348/problem/D
Code: 1348D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-09-09.03.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> c;
    for(int b = 0; (1LL << b) < n; ++b){
        int v = 1 << b;
        c.push_back(v);
        n -= v;
    }

    c.push_back(n);

    sort(begin(c), end(c));

    int sz = c.size();
    cout << sz - 1 << "\n";
    for(int i = 0; i + 1 < sz; ++i){
        cout << c[i + 1] - c[i] << " ";
    }
    cout << "\n";
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
