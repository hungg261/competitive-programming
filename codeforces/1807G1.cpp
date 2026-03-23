/******************************************************************************
Link: https://codeforces.com/problemset/problem/1807/G1
Code: 1807G1
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-20.55.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    sort(begin(arr) + 1, end(arr));
    if(arr[1] != 1){
        cout << "NO\n";
        return;
    }

    int pre = arr[1];
    for(int i = 2; i <= n; ++i){
        if(pre < arr[i]){
            cout << "NO\n";
            return;
        }
        pre += arr[i];
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
