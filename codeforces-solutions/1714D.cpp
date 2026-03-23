/******************************************************************************
Link: https://codeforces.com/contest/1714/problem/D
Code: 1714D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-12-09.46.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int sz = s.size();
    s = "#" + s;

    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> dp(sz + 1, 1e9);
    vector<pair<int, int>> trace(sz + 1, {-1, -1});
    dp[0] = 0;

    for(int i = 1; i <= sz; ++i){
        for(int j = 0; j < n; ++j){
            int cursz = arr[j].size();
            if(cursz > i) continue;

            if(s.substr(i - cursz + 1, cursz) == arr[j]){
                int best_idx = -1;
                for(int d = 0; d < cursz; ++d){
                    if(best_idx == -1 || dp[i - d - 1] < dp[best_idx])
                        best_idx = i - d - 1;

                    if(dp[best_idx] + 1 < dp[i]){
                        dp[i] = dp[best_idx] + 1;
                        trace[i] = {j, best_idx};
                    }
                }
            }
        }
    }

    if(dp[sz] == 1e9){
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> res;
    int cur = sz;
    while(true){
        int idx = trace[cur].first;
        if(idx == -1) break;

        res.emplace_back(idx, cur - (int)arr[idx].size() + 1);
        cur = trace[cur].second;
    }

    cout << res.size() << '\n';

    reverse(begin(res), end(res));
    for(const pair<int, int>& p: res){
        cout << p.first + 1 << ' ' << p.second << '\n';
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
