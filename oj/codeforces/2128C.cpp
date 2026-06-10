/******************************************************************************
Link: https://codeforces.com/problemset/problem/2128/C
Code: 2128C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-21.39.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int minVal = 1e9;
    for(int i = 1; i < n; ++i){
        minVal = min(minVal, arr[i - 1]);
        if(arr[i - 1] == arr[i] || minVal >= arr[i] - (arr[i] - 1) / 2) continue;
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
