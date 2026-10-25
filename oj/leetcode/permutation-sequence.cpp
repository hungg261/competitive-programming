/******************************************************************************
Link: https://leetcode.com/problems/permutation-sequence/description
Code: permutation-sequence
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-15.48.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i){
            fact[i] = fact[i - 1] * i;
        }

        string ans;
        int mask = 0; // check if a digit is used
        for(int pos = 1; pos <= n; ++pos){
            for(int i = 1; i <= n; ++i){
                if(mask >> i & 1) continue;

                int cnt = fact[n - pos];
                if(k > cnt) k -= cnt;
                else{
                    ans += i + '0';
                    mask |= 1 << i;
                    break;
                }
            }
        }

        return ans;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << Solution().getPermutation(n, k);

    return 0;
}
#endif // __________
