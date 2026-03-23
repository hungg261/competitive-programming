#include<bits/stdc++.h>
#define pic pair<int, char>
using namespace std;

void solve(string s){
    int n = s.size();

    int mark[26] = {};
    for(char c: s){
        ++mark[c - 'A'];
    }
    for(int ch = 0; ch < 26; ++ch){
        if(mark[ch] * 2 - 1 > n){
            cout << "-1\n";
            return;
        }
    }

    string res(n, '#');

    for(int ch = 0; ch < 26; ++ch){
        while(mark[ch] > 0){
            for(int i = res.find("#"); i < n && mark[ch] > 0; i += 2){
                res[i] = ch + 'A';
                --mark[ch];
            }
        }
    }

    char invalid = '#';
    int invalid_cnt = 0;
    for(int i = 1; i < n; ++i){
        if(res[i - 1] == res[i]){
            invalid = res[i];
            break;
        }
    }

    if(invalid == '#'){
        cout << res << '\n';
        return;
    }

    string temp, replacement = "#";
    for(char c: res){
        if(c != invalid){
            temp += c;
            replacement += c;
            replacement += '#';
        }
        else ++invalid_cnt;
    }

    int sz = temp.size();
    for(int i = 0; i < sz; ++i){
        if(temp[i - 1] == temp[i]){
            for(int j = i * 2; j < sz * 2 + 1 && invalid_cnt > 0; j += 2){
                replacement[j] = invalid;
                --invalid_cnt;
            }

            if(invalid_cnt > 0){
                for(int j = i * 2; j >= 0 && invalid_cnt > 0; j -= 2){
                    if(replacement[j] != '#') continue;

                    replacement[j] = invalid;
                    --invalid_cnt;
                }
            }
        }
    }

    for(int i = replacement.find_last_of("#"); i >= 0 && invalid_cnt > 0; i -= 2){
        replacement[i] = invalid;
        --invalid_cnt;
    }

    int first = -1, last = -1;
    sz = replacement.size();

    for(int i = 0; i < sz; ++i){
        if(replacement[i] == invalid){
            if(first == -1) first = i;
            last = i;
        }
    }

    string middle;
    for(int i = first + 1; i < last; i += 2){
        middle += replacement[i];
    }
    sort(begin(middle), end(middle));
    for(int i = last - 1; i > first; i -= 2){
        replacement[i] = middle.back();
        middle.pop_back();
    }

    for(char ch: replacement){
        if(ch != '#') cout << ch;
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    solve(s);

    return 0;
}
