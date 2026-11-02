/******************************************************************************
Link: https://leetcode.com/problems/beautiful-arrangement/description
Code: beautiful-arrangement
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-02-12.06.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int val, int pos){
        return val % pos == 0 || pos % val == 0;
    }

public:
    int countArrangement(int n) {
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;

        for(int mask = 0; mask < (1 << n); ++mask){
            int idx = __builtin_popcount(mask) + 1;
            for(int i = 0; i < n; ++i){
                if(~mask >> i & 1){
                    if(check(i + 1, idx))
                        dp[mask | (1 << i)] += dp[mask];
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    cout << Solution().countArrangement(n);

    return 0;
}
#endif // __________
