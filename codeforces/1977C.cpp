/******************************************************************************
Link: https://codeforces.com/contest/1977/problem/C
Code: 1977C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-12-17.53.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXVAL = 1e9 + 5;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(begin(a) + 1, end(a));

    vector<int> d(n + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if(a[i] % a[j] == 0) ++d[i];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if()
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
