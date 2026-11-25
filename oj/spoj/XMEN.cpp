/******************************************************************************
Link: https://www.spoj.com/problems/XMEN
Code: XMEN
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-25-08.53.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> pos(n + 1);
    for(int i = 1; i <= n; ++i) pos[a[i]] = i;

    vector<int> tail;
    for(int i = 1; i <= n; ++i){
        int v = pos[b[i]];
        if(tail.empty() || v > tail.back()) tail.push_back(v);
        else *lower_bound(begin(tail), end(tail), v) = v;
    }

    cout << tail.size() << "\n";
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
