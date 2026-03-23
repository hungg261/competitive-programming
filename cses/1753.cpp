#include<bits/stdc++.h>
using namespace std;

vector<int> KMP(const string& s, int len){
    vector<int> pi(len);
    pi[0] = 0;

    for(int i = 1; i < len; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }

        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }

    return pi;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    string t = b + '#' + a;
    int sz = t.size();

    vector<int> pi = KMP(t, sz);
    int ans = 0;
    for(int i = m + 1; i < sz; ++i){
        if(pi[i] == m) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
