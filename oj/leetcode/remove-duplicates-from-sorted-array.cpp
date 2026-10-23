/******************************************************************************
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array
Code: remove-duplicates-from-sorted-array
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-12.08.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(begin(nums), end(nums)) - begin(nums);
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int &ele: a) cin >> ele;

    int sz = Solution().removeDuplicates(a);
    cout << sz << "\n";

    for(int i = 0; i < sz; ++i){
        cout << a[i] << " ";
    }

    return 0;
}
#endif // __________
