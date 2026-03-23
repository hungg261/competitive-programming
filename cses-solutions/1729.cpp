/******************************************************************************
Link: https://cses.fi/problemset/task/1729
Code: 1729
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-01.21.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1729.INP","r",stdin);
    //freopen("1729.OUT","w",stdout);

    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for(int& ele: p) cin >> ele;

    vector<int> dp(n + 1);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j: p){
            if(i >= j)
                dp[i] |= !dp[i - j];
        }

        cout << (dp[i] ? "W" : "L");
    }

    return 0;
}
