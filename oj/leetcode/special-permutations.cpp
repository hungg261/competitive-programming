/******************************************************************************
Link: https://leetcode.com/problems/special-permutations/description
Code: special-permutations
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-15.32.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    bool _is_valid(int val1, int val2){
        return val1 % val2 == 0 || val2 % val1 == 0;
    }

    vector<int> _fact;
    void _init(int sz){
        _fact.resize(sz + 1);
        _fact[0] = 1;
        for(int i = 1; i <= sz; ++i)
            _fact[i] = 1LL * _fact[i - 1] * i % MOD;
    }

    int powmod(int a, int b, int mod){
        int res = 1 % mod;
        a %= mod;
        while(b > 0){
            if(b & 1) res = 1LL * res * a % mod;
            a = 1LL * a * a % mod;
            b >>= 1;
        }
        return res;
    }

public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));

        for(int i = 0; i < n; ++i)
            dp[1 << i][i] = 1;

        for(int mask = 0; mask < (1 << n); ++mask){
            for(int i = 0; i < n; ++i){
                if(~mask >> i & 1) continue;
                for(int j = 0; j < n; ++j){
                    if(i == j || (~mask >> j & 1)) continue;

                    if(_is_valid(nums[j], nums[i])){
                        int prev_mask = mask ^ (1 << i);
                        dp[mask][i] = (dp[mask][i] + dp[prev_mask][j]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = (ans + dp[(1 << n) - 1][i]) % MOD;
        }

        _init(n);
        map<int, int> mp;
        for(int x: nums) mp[x]++;

        for(const auto &p: mp){
            ans = 1LL * ans * powmod(_fact[p.second], MOD - 2, MOD) % MOD;
        }

        return ans;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << Solution().specialPerm(a);

    return 0;
}
#endif // __________
