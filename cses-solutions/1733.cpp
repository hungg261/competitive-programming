#include<bits/stdc++.h>
using namespace std;

vector<int> KMP(string s){
    int sz = s.size();

    vector<int> pi(sz);
    pi[0] = 0;
    for(int i = 1; i < sz; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j - 1];
        }

        if(s[j] == s[i]) ++j;
        pi[i] = j;
    }

    return pi;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;

    vector<int> pi = KMP(s);
    int sz = s.size();

    int window = sz - pi[sz - 1];
    for(int cur = window; cur< sz; cur += window){
        cout << cur << ' ';
    }
    cout << sz << '\n';

    return 0;
}
