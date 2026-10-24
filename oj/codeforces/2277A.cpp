/******************************************************************************
Link: https://codeforces.com/contest/2277/problem/A
Code: 2277A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-24-18.06.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(begin(a), end(a), greater<int>());

    int mex = 0;
    while(true){
        auto it = find(begin(a), end(a), mex);
        if(end(a) - it < k) break;
        a.erase(it, it + k);
        ++mex;
    }

    cout << mex << "\n";
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
