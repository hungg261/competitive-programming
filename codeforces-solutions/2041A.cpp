/******************************************************************************
Link: https://codeforces.com/problemset/problem/2041/A
Code: 2041A
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-17.27.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int arr[4];
    for(int i = 0; i < 4; ++i) cin >> arr[i];

    auto in = [&arr](int x){ return find(arr, arr + 4, x) != arr + 4; };

    for(int res = 1; res <= 5; ++res){
        if(!in(res)){
            cout << res << '\n';
            break;
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
