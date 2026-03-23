/******************************************************************************
Link: https://codeforces.com/problemset/problem/2074/C
Code: 2074C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-10-23.46.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x;
    cin >> x;

    int temp = x;
    int bit[2] = {};

    auto check = [](int a, int b, int c){
        return a + b > c && b + c > a && c + a > b;
    };


    int res = -1;
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < 30; ++j){
            int y = (1 << i) | (1 << j);
            if(y < x && check(x, y, x ^ y)){
                res = y;
            }
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
