/******************************************************************************
Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description
Code: minimum-operations-to-make-a-subsequence
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-25-08.40.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        vector<int> temp = target;
        auto f = [&temp](int x){ return lower_bound(begin(temp), end(temp), x) - begin(temp); };

        {
            sort(begin(temp), end(temp));
            for(int &x: target) x = f(x);
        }

        vector<int> pos(temp.size(), -1);
        for(int i = 0; i < (int)target.size(); ++i){
            pos[target[i]] = i;
        }

        vector<int> tail;
        for(int x: arr){
            int val = f(x);
            if(val >= (int)temp.size() || temp[val] != x) continue;

            int v = pos[val];
            if(v != -1){
                if(tail.empty() || v > tail.back()) tail.push_back(v);
                else *lower_bound(begin(tail), end(tail), v) = v;
            }
        }

        return target.size() - tail.size();
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> tar(n), arr(m);
    for(int &ele: tar) cin >> ele;
    for(int &ele: arr) cin >> ele;

    cout << Solution().minOperations(tar, arr);

    return 0;
}
#endif // __________
