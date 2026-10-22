#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prv;

    inline int priority(char op){
        switch (op){
            case '+': return 0;
            case '-': return 0;
            case '*': return 1;
            case '/': return 1;
            default: return -1;
        }
    }

    inline int eval(int a, int b, char op){
        switch (op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: abort();
        }
    }

    int parse(int l, int r, const string &s){
        if(l > r) return 0;

        int mid = prv[r];
        if(mid < l){
            vector<string> tokens;
            vector<char> ops;
            string cur = "";
            for(int i = l; i <= r; ++i){
                if(isalnum(s[i])){
                    cur += s[i];
                }
                else{
                    if(!cur.empty()){
                        tokens.push_back(cur);
                        cur = "";
                    }

                    ops.push_back(s[i]);
                }
            }
            if(!cur.empty()) tokens.push_back(cur);

            if(ops.empty()) return stoi(tokens[0]);

            int res = eval(stoi(tokens[0]), stoi(tokens[1]), ops[0]);
            for(int i = 1; i < (int)ops.size(); ++i){
                res = eval(res, stoi(tokens[i + 1]), ops[i]);
            }
            return res;
        }

        return eval(parse(l, mid - 1, s), parse(mid + 1, r, s), s[mid]);
    }

public:
    int calculate(string s) {
        {
            string temp = "";
            for(char c: s)
                if(c != ' ') temp += c;
            s = temp;
        }

        int sz = s.size();
        prv.resize(sz);

        for(int i = 0; i < sz; ++i){
            if(i > 0) prv[i] = prv[i - 1];
            else prv[i] = -1;

            if(priority(s[i]) == 0) prv[i] = i;
        }

        return parse(0, sz - 1, s);
    }
};

#ifdef __________
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    getline(cin, s);

    cout << Solution().calculate(s) << "\n";

    return 0;
}
#endif // __________
