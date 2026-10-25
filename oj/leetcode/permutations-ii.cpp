/******************************************************************************
Link: https://leetcode.com/problems/permutations-ii/description
Code: permutations-ii
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-16.14.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        do{
            res.push_back(nums);
        } while(next_permutation(begin(nums), end(nums)));

        return res;
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

    for(const auto &v: Solution().permuteUnique(a)){
        for(int x: v) cerr << x << " ";
        cerr << endl;
    }

    return 0;
}
#endif // __________
