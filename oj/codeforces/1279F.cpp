/******************************************************************************
Link: https://codeforces.com/contest/1279/problem/F
Code: 1279F
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-21.16.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
vector<vector<pair<int, int>>> dp;
int n, k, l;
string s;

int g(const pair<int, int>& a){
    return min(a.first, a.second);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> l;
    cin >> s;

    dp.resize(k + 1, vector<pair<int, int>>(n + 1, make_pair(INF, INF)));

    dp[0][0] = {0, 0};
    for(int c = 1; c <= k; ++c){
        for(int i = l; i <= n; ++i){
            dp[c][i] = dp[c][i - 1];

            int j = i - l + 1;

            pair<int, int> prv = dp[c - 1][j - 1];
            if(prv.first < prv.second)
                swap(prv.first, prv.second);

            prv.first += l;

            if(g(prv) < g(dp[c][i]))
                dp[c][i] = prv;
        }
    }

    for(int c = 0; c <= k; ++c){
        for(int i = 0; i <= n; ++i){
            cerr << dp[c][i].first << "/" << dp[c][i].second << ' ';
        }
        cerr << '\n';
    }

    cout << g(dp[k][n]) << '\n';

    return 0;
}
