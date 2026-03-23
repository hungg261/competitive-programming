/******************************************************************************
Link: https://codeforces.com/problemset/problem/2197/A
Code: 2197A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-22-13.15.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int dsum(int n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve(){
    int x;
    cin >> x;

    int res = 0;
    for(int d = 1; d <= 5000; ++d){
        if(d == dsum(x + d)){
            ++res;
        }
    }

    cout << res << '\n';
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
