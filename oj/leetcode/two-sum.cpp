/******************************************************************************
Link: https://leetcode.com/problems/two-sum/description
Code: two-sum
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-22-23.21.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp, pos;
        for(int i = 0; i < (int)nums.size(); ++i){
            int x = nums[i];
            if(mp.count(target - x)){
                return {i, pos[target - x]};
            }

            mp[x]++;
            pos[x] = i;
        }

        return {-1, -1};
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int x: Solution().twoSum(a, t))
        cout << x << " ";

    return 0;
}
#endif // __________
