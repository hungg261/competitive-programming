/******************************************************************************
Link: https://codeforces.com/contest/2214/problem/C
Code: 2214C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-01-22.06.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int arr[3];
    for(int i =0 ; i < 3; ++i) cin >> arr[i];

    sort(arr, arr + 3);

    cout << (arr[0] ^ arr[1] ^ arr[2]) - arr[1] << "\n";
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
