/******************************************************************************
Link: https://leetcode.com/problems/make-sum-divisible-by-p/description
Code: make-sum-divisible-by-p
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-20.07.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int, int> mp;
        int prefix = 0; mp[prefix] = 0;
        int sz = nums.size();

        int sum = 0;
        for(int i = 0; i < sz; ++i)
            sum = (sum + nums[i]) % p;

        if(sum == 0) return 0;

        int res = INT_MAX;
        for(int i = 1; i <= sz; ++i){
            prefix = (prefix + nums[i - 1]) % p;

            int prv_value = ((prefix - sum) % p + p) % p;
            if(mp.count(prv_value)){
                res = min(res, i - mp[prv_value]);
            }

            mp[prefix] = i;
        }

        return res >= sz ? -1 : res;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    cout << Solution().minSubarray(a, p);

    return 0;
}
#endif // __________
