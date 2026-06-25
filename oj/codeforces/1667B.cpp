/******************************************************************************
Link: https://codeforces.com/contest/1667/problem/B
Code: 1667B
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-25-16.02.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

template<typename Op> struct FenwickTree{
    int n;
    vector<int> BIT;
    int LIMIT;
    Op cmp;

    FenwickTree() = default;
    FenwickTree(int sz, int LIM): n(sz), LIMIT(LIM){ BIT.resize(sz + 1, LIMIT); }

    void update(int idx, int val){
        ++idx;

        for(int i = idx; i <= n; i += i & -i){
            if(cmp(val, BIT[i])) BIT[i] = val;
        }
    }

    int get(int idx){
        ++idx;

        int res = LIMIT;
        for(int i = idx; i > 0; i -= i & -i){
            if(cmp(BIT[i], res)) res = BIT[i];
        }
        return res;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<int> P(n + 1); P[0] = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        P[i] = P[i - 1] + cur;
    }

    {
        vector<int> temp = P;
        sort(begin(temp), end(temp)); temp.erase(unique(begin(temp), end(temp)), end(temp));
        for(int i = 0; i <= n; ++i){
            P[i] = lower_bound(begin(temp), end(temp), P[i]) - begin(temp) + 1;
        }
    }

    vector<int> dp(n + 1);
    FenwickTree<greater<int>> fwt1(n + 1, LLONG_MIN / 2);
    FenwickTree<greater<int>> fwt2(n + 1, LLONG_MIN / 2);
    vector<int> mp(n + 5, LLONG_MIN / 2);

    dp[0] = 0;
    for(int i = 0; i <= n; ++i){
        if(i > 0) dp[i] = max({mp[P[i]], i + fwt1.get(P[i] - 1), -i + fwt2.get(n - P[i])});

        fwt1.update(P[i], dp[i] - i);
        fwt2.update(n - P[i] + 1, dp[i] + i);
        mp[P[i]] = max(mp[P[i]], dp[i]);
    }

    cout << dp[n] << "\n";
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
