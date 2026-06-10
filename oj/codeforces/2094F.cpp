/******************************************************************************
Link: https://codeforces.com/contest/2094/problem/F
Code: 2094F
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-29-21.59.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    if(m % k == 0){
        for(int i = 1; i <= n; ++i){
            for(int t = 1; t <= m / k; ++t){
                for(int j = 0; j < k; ++j){
                    int cur = j;
                    if(i & 1) cur = (cur + k - 1) % k;

                    cout << cur + 1 << ' ';
                }
            }
            cout << '\n';
        }
        return;
    }

    int filled = 0;
    for(int t = 1; t <= n * m / k; ++t){
        for(int i = 1; i <= k; ++i){
            cout << i << ' ';
            ++filled;

            if(filled % m == 0) cout << '\n';
        }
    }
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
