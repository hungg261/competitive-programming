/******************************************************************************
Link: https://leetcode.com/problems/palindrome-number/description
Code: palindrome-number
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-22-22.54.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x), t = s;
        reverse(begin(s), end(s));

        return s == t;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
#endif // __________
