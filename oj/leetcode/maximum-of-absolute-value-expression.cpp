/******************************************************************************
Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/description
Code: maximum-of-absolute-value-expression
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-24-22.42.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int n, const vector<int> &x, const vector<int> &y, const vector<int> &z){
    int ans = 0;
    for(int mask = 0; mask < 8; ++mask){
        int mn = INF, mx = -INF;
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            if(mask & 1) cur += x[i];
            else cur -= x[i];
            if(mask & 2) cur += y[i];
            else cur -= y[i];
            if(mask & 4) cur += z[i];
            else cur -= z[i];

            mn = min(mn, cur);
            mx = max(mx, cur);
        }

        ans = max(ans, mx - mn);
    }

    return ans;
}

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        arr1.insert(begin(arr1), 0);
        arr2.insert(begin(arr2), 0);

        vector<int> idx(n + 1);
        iota(begin(idx) + 1, end(idx), 1);

        return solve(n, arr1, arr2, idx);
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
#endif // __________
