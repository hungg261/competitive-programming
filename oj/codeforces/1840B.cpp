/******************************************************************************
Link: https://codeforces.com/problemset/problem/1840/B
Code: 1840B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-20.07.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    if(k > 30){
        cout << n + 1 << '\n';
        return;
    }

    cout << min(n + 1, 1LL << k) << '\n';
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
