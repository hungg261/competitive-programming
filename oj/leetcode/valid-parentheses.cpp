/******************************************************************************
Link: https://leetcode.com/problems/valid-parentheses/description
Code: valid-parentheses
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-12.05.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }

        return st.empty();
    }
};


#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    cout << Solution().isValid(s);

    return 0;
}
#endif // __________
