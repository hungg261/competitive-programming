/******************************************************************************
Link: https://leetcode.com/problems/longest-common-prefix/description
Code: longest-common-prefix
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-22-23.27.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrefix(const string &p, string s){
        if(p.size() > s.size()) return false;
        while(p.size() < s.size()) s.pop_back();
        return p == s;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = strs[0];
        for(int i = 1; i < (int)strs.size(); ++i){
            while(!isPrefix(ans, strs[i])){
                ans.pop_back();
                if(ans.empty()) return "";
            }
        }
        return ans;
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
#endif // __________
