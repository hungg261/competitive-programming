#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNum(const string &N){
        if(N == "-") return false;
        for(char c: N)
            if(!(c == '-' || ('0' <= c && c <= '9'))) return false;
        return true;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(const string &s: tokens){
            if(isNum(s)){
                int value = stoi(s);
                sta.push(value);
            }
            else{
                if(s == "+"){
                    int v2 = sta.top(); sta.pop();
                    int v1 = sta.top(); sta.pop();
                    sta.push(v1 + v2);
                }
                else if(s == "-"){
                    int v2 = sta.top(); sta.pop();
                    int v1 = sta.top(); sta.pop();
                    sta.push(v1 - v2);
                }
                else if(s == "*"){
                    int v2 = sta.top(); sta.pop();
                    int v1 = sta.top(); sta.pop();
                    sta.push(v1 * v2);
                }
                else if(s == "/"){
                    int v2 = sta.top(); sta.pop();
                    int v1 = sta.top(); sta.pop();
                    sta.push(v1 / v2);
                }
            }
        }

        return sta.top();
    }
};


#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> tokens;
    string cur;
    while(cin >> cur){
        if(cur == "stop") break;
        tokens.push_back(cur);
    }

    cout << Solution().evalRPN(tokens) << "\n";

    return 0;
}
#endif // __________
