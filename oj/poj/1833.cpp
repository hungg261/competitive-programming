/******************************************************************************
Link: http://poj.org/problem?id=1833
Code: 1833
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-18.01.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    while(k--){
        next_permutation(begin(a), end(a));
    }

    for(int x: a) cout << x << " ";
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
