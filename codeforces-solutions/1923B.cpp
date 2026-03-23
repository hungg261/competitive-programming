/******************************************************************************
Link: https://codeforces.com/problemset/problem/1923/B
Code: 1923B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-22.02.59
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> pos(n * 2 + 5, -1);
    vector<pair<int, int>> monsters(n + 1);
    for(int i = 1; i <= n; ++i) cin >> monsters[i].first;
    for(int i = 1; i <= n; ++i) cin >> monsters[i].second;
    for(int i = 1; i <= n; ++i){
        pos[monsters[i].second + n] = monsters[i].first;
    }

    int left = 0;
    for(int d = 1; d <= n; ++d){
        left += k;
        if(pos[n - d] != -1){
            left -= pos[n - d];
        }
        if(pos[n + d] != -1){
            left -= pos[n + d];
        }

        if(left < 0){
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
