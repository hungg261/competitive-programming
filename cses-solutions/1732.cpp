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
    int idx = (int)s.size() - 1;

    vector<int> res;
    while(idx > 0){
        if(pi[idx] > 0) res.push_back(pi[idx]);
        idx = pi[idx] - 1;
    }

    while(!res.empty()){
        cout << res.back() << ' ';
        res.pop_back();
    }

    return 0;
}
