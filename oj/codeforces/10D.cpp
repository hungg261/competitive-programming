/******************************************************************************
Link: https://codeforces.com/problemset/problem/10/D
Code: 10D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-07.23.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int m; cin >> m;
    vector<int> b(m + 1);
    for(int i = 1; i <= m; ++i) cin >> b[i];

    vector<int> dp(m + 1, 0), trace(m + 1, -1);
    for(int i = 1; i <= n; ++i){
        int best = -1;
        for(int j = 1; j <= m; ++j){
            if(b[j] < a[i]){
                if(best == -1 || dp[j] > dp[best]){
                    best = j;
                }
            }
            else if(b[j] == a[i]){
                if(dp[best] + 1 > dp[j]){
                    dp[j] = dp[best] + 1;
                    trace[j] = best;
                }
            }
        }
    }

    int cur = max_element(begin(dp) + 1, end(dp)) - begin(dp);
    vector<int> res;
    while(cur != -1 && dp[cur] > 0){
        res.push_back(b[cur]);
        cur = trace[cur];
    }
    reverse(begin(res), end(res));

    cout << res.size() << '\n';
    for(int ele: res) cout << ele << ' ';
    cout << '\n';

    return 0;
}
