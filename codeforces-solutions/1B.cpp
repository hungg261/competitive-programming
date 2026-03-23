#include<bits/stdc++.h>
#define int long long
using namespace std;

bool isNum(char c){
    return '0' <= c && c <= '9';
}

int is_reversed(const string& token){
    int sz = token.size();
    int diffcnt = 1;
    for(int i = 1; i < sz; ++i){
        if(isNum(token[i]) != isNum(token[i - 1])){
            ++diffcnt;
        }
    }

    return diffcnt == 2;
}

vector<string> separate(const string& token){
    int sz = token.size();
    vector<string> res;
    string cur = string(1, token[0]);
    for(int i = 1; i < sz; ++i){
        if(isNum(token[i]) != isNum(token[i - 1])){
            res.push_back(cur);
            cur = "";
        }
        cur += token[i];
    }
    res.push_back(cur);

    return res;
}

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string type1(const string& token){
    vector<string> mini_tokens = separate(token);
    int c = stoi(mini_tokens[3]) - 1;

    cerr << c << '\n';

    string C;
    while(c > 0){
        C += ALPHABET[c % 26];
        c /= 26;
    }
    reverse(begin(C), end(C));
    C += mini_tokens[1];

    return C;
}

string type2(const string& token){
    vector<string> mini_tokens = separate(token);

    int c = 0;
    for(char ch: mini_tokens[0]){
        c = c * 26 + (find(begin(ALPHABET), end(ALPHABET), ch) - begin(ALPHABET));
    }

    return to_string(c + 1);
}

void solve(){
    string token;
    cin >> token;

    string res;

    if(is_reversed(token)) res = type2(token);
    else res = type1(token);

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
