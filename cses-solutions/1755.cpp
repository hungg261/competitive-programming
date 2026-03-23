#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;

    int n =s.size();
    int counter[26] = {};
    for(char element: s){
        ++counter[element - 'A'];
    }

    bool mod1 = false;
    char char_le = -1;
    for(int character = 0; character < 26; ++character){
        if(counter[character] % 2 != 0){
            if(mod1){
                cout << "NO SOLUTION\n";
                return 0;
            }
            mod1 = true;
            char_le = character + 'A';
        }
    }

    string result(n, '#');
    int idx = 0;
    for(int character = 0; character < 26; ++character){
        while(counter[character] > 1){
            result[idx] = character + 'A';
            result[n - idx - 1] = character + 'A';

            ++idx;
            counter[character] -= 2;
        }
    }
    if(mod1){
        result[n / 2] = char_le;
    }

    cout << result << '\n';
    return 0;
}
