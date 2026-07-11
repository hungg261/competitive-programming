/******************************************************************************
Link: https://codeforces.com/contest/1450/problem/C1
Code: 1450C1
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-11-16.56.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> T(n);
    for(int i = 0; i < n; ++i){
        cin >> T[i];
    }

    int cnt[3] = {};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(T[i][j] != '.')
                ++cnt[(i + j) % 3];
        }
    }

    int mn = min_element(cnt, cnt + 3) - cnt;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(T[i][j] != '.' && (i + j) % 3 == mn)
                T[i][j] = 'O';
        }
    }

    for(int i = 0; i < n; ++i)
        cout << T[i] << "\n";
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
