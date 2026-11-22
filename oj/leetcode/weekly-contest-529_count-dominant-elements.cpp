/******************************************************************************
Link: https://leetcode.com/contest/weekly-contest-529/problems/count-dominant-elements/description
Code: weekly-contest-529_count-dominant-elements
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-22-09.35.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        if(nums.empty()) return 0;
        else if((int)nums.size() == 1) return 1;

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0) res += nums[i] >= nums[i + 1];
            else if(i == n - 1) res += nums[i] >= nums[i - 1];
            else res += nums[i] * 2 >= nums[i - 1] + nums[i + 1];
        }

        return res;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int &ele: a) cin >> ele;

    cout << Solution().countDominantElements(a);

    return 0;
}
#endif // __________
