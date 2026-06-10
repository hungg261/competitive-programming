/******************************************************************************
Link: https://codeforces.com/problemset/problem/2146/B
Code: 2146B
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-26-21.32.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> mp(m + 1, 0);
    vector<vector<int>> S(n);

    for(int i = 0; i < n; ++i){
        int len; cin >> len;
        for(int j = 0; j < len; ++j){
            int cur; cin >> cur;
            S[i].push_back(cur);

            mp[cur]++;
        }
    }

    for(int e = 1; e <= m; ++e){
        if(mp[e] == 0){
            cout << "NO\n";
            return;
        }
    }

    int ways = 1;
    for(int i = 0; i < n; ++i){
        auto run = [&](){
            bool ok = true;
            for(int s: S[i]){
                if(--mp[s] < 1){
                    ok = false;
                    break;
                }
            }

            return ok;
        };

        if(run() && ++ways >= 3){
            cout << "YES\n";
            return;
        }

        for(int s: S[i]) ++mp[s];
    }

    cout << "NO\n";
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
