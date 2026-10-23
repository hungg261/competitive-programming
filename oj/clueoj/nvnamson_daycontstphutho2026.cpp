/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_daycontstphutho2026
Code: nvnamson_daycontstphutho2026
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-08.04.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

namespace Brute{

void solve(const vector<int> &a, int n){
    int res = -1;
    for(int mask = 0; mask < (1 << n); ++mask){
        int sum = 0, last = -1;
        for(int i = 1; i <= n; ++i){
            if(mask >> (i - 1) & 1){
                if(last + 1 == i) goto nxt;
                sum += a[i];
                last = i;
            }
        }

        if(sum & 1) res = max(res, sum);
        nxt:;
    }

    cout << res << "\n";
}

}

namespace Solve{

void solve(const vector<int> &a, int n){

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2)));
    dp[0][0][0] = 0;
    dp[0][1][0] = -INF;
    dp[0][0][1] = -INF;
    dp[0][1][1] = -INF;

    auto f = [&dp, &n](int i, int j, int k){
        if(0 <= i && i < n &&
           0 <= j && j < 2 &&
           0 <= k && k < 2)
            return dp[i][j][k];
        return -INF;
    };

    for(int i = 1; i <= n; ++i){
        int b = a[i] % 2;

        dp[i][0][0] = max(f(i - 1, 0, 0), f(i - 1, 1, 0));
        dp[i][0][1] = max(f(i - 1, 0, 1), f(i - 1, 1, 1));

        dp[i][1][0] = max(f(i - 1, 0, b), f(i - 2, 1, b)) + a[i];
        dp[i][1][1] = max(f(i - 1, 0, b ^ 1), f(i - 2, 1, b ^ 1)) + a[i];
    }

    int res = max(dp[n][0][1], dp[n][1][1]);
    cout << (res < 0 ? -1 : res) << "\n";
}

}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    Solve::solve(a, n);
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
