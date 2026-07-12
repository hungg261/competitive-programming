/******************************************************************************
Link: https://codeforces.com/contest/1450/problem/C2
Code: 1450C2
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-11-17.23.02
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

    auto subsolve = [&](char c, char t){
        int cnt[3] = {};
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(T[i][j] == c) ++cnt[(i + j) % 3];
            }
        }

        int mn = min_element(cnt, cnt + 3) - cnt;
        for(int x = 0; x < n; ++x){
            for(int y = 0; y < n; ++y){
                if(T[x][y] == c && (x + y) % 3 == mn){
                    T[x][y] = t;
                }
            }
        }
    };

    for(int i = 0; i < n * 5; ++i){
        subsolve('X', 'O');
        subsolve('O', 'X');
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
