/******************************************************************************
Link: https://codeforces.com/problemset/problem/2060/D
Code: 2060D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-21.07.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];

    for(int i = 1; i < n; ++i){
        int delta = min(arr[i], arr[i + 1]);
        arr[i] -= delta;
        arr[i + 1] -= delta;
    }

    for(int i = 1; i < n; ++i){
        if(arr[i] > arr[i + 1]){
            cout << "NO\n";
            return;
        }
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
