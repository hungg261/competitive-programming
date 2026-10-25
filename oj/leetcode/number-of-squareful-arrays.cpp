/******************************************************************************
Link: https://leetcode.com/problems/number-of-squareful-arrays/description
Code: number-of-squareful-arrays
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-14.58.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    inline int _pow2(int x){ return x * x; }
    inline bool is_square(int x){
        int sq = sqrt(x);
        if(_pow2(sq) == x) return true;
        if(_pow2(sq - 1) == x) return true;
        if(_pow2(sq + 1) == x) return true;
        return false;
    }

    bool _is_valid(int val1, int val2){
        return is_square(val1 + val2);
    }

    vector<int> fact;
    void _init(int sz){
        fact.resize(sz + 1);
        fact[0] = 1;
        for(int i = 1; i <= sz; ++i)
            fact[i] = fact[i - 1] * i;
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
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
                        dp[mask][i] += dp[prev_mask][j];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += dp[(1 << n) - 1][i];
        }

        _init(n);
        map<int, int> mp;
        for(int x: nums) mp[x]++;

        for(const auto &p: mp){
            ans /= fact[p.second];
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

    cout << Solution().numSquarefulPerms(a);

    return 0;
}
#endif // __________
