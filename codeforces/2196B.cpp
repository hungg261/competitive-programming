/******************************************************************************
Link: https://codeforces.com/contest/2196/problem/B
Code: 2196B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-26-18.06.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] <= n / a[i]){
            for(int j = 1; j <= a[i]; ++j){

            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
