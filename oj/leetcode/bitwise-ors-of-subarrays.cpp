/******************************************************************************
Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/description
Code: bitwise-ors-of-subarrays
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-10.20.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> cur;
        set<int> all;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            set<int> nxt = {arr[i]};
            for(int val: cur){
                nxt.insert(val | arr[i]);
            }

            cur = nxt;
            for(int x: cur)
                all.insert(x);
        }

        return all.size();
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

    cout << Solution().subarrayBitwiseORs(a);

    return 0;
}
#endif // __________
