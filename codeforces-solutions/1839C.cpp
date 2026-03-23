/******************************************************************************
Link: https://codeforces.com/problemset/problem/1839/C
Code: 1839C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-13-09.48.34
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

    if(a[n] == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = n; i >= 1;){
        int j = i - 1;
        for(; j >= 1 && a[j] == 1; --j){
            cout << "0 ";
        }

        cout << i - j - 1 << ' ';

        i = j;
    }
    cout << '\n';
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
