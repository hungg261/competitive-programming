/******************************************************************************
Link: https://codeforces.com/problemset/problem/1937/B
Code: 1937B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-13-20.49.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> arr(2);
    for(int i = 0; i < 2; ++i) cin >> arr[i];

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(2));

    dp[1][0] = dp[1][1] = {0, 1};
    for(int dcheo = 2; dcheo <= n - 1; ++dcheo){
        for(int i = 0; i < 2; ++i){
            dp[dcheo][i] = {1e9, 1};

            for(int x = 0; x < 2; ++x){
                int j = dcheo - x;


                int lastDp, lastCnt; tie(lastDp, lastCnt) = dp[dcheo - 1][i];
                int curDp, curCnt; tie(curDp, curCnt) = dp[dcheo][i];
                int newDp = lastDp * 2 + (arr[i][j] - '0');

                if(newDp < curDp){
                    dp[dcheo][i] = {newDp, lastCnt};
                }
                else if(newDp == curDp){
                    dp[dcheo][i] = {newDp, lastCnt + 1};
                }

                cerr << dcheo << ' ' << i << ' ' << j << " | " << dp[dcheo][i].first << ' ' << dp[dcheo][i].second << '\n';
            }


        }

        if(dp[dcheo][0].first > dp[dcheo][1].first) tie(dp[dcheo][0].first, dp[dcheo][1].first) = make_pair(1, 0);
        else if(dp[dcheo][0].first > dp[dcheo][1].first) tie(dp[dcheo][0].first, dp[dcheo][1].first) = make_pair(0, 1);
    }

    cout << dp[n - 1][0].second << ' ' << dp[n - 1][1].second << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
