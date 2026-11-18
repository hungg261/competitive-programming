/******************************************************************************
Link: https://leetcode.com/problems/increasing-triplet-subsequence/description
Code: increasing-triplet-subsequence
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-18-21.54.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) return false;

        vector<int> tail = {nums[0]};
        for(int i = 1; i < (int)nums.size(); ++i){
            if(nums[i] > tail.back()){
                tail.push_back(nums[i]);
                if((int)tail.size() == 3) return true;
            }
            else *lower_bound(begin(tail), end(tail), nums[i]) = nums[i];
        }

        return false;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    cout << Solution().increasingTriplet(arr);

    return 0;
}
#endif // __________
