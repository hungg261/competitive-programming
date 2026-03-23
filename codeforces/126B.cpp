#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6;
string s;
int n;

vector<int> KMP(const string& s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j - 1];
        }

        if(s[j] == s[i]) ++j;
        pi[i] = j;
    }

    return pi;
}

bool check(int len, const vector<int>& pi){
    for(int i = len; i < n - 1; ++i){
        if(pi[i] == len) return true;
    }
    return false;
}

void solve(){
    cin >> s;

    n = s.size();
    vector<int> pi = KMP(s);

    s = "#" + s;

    int len = pi[n - 1];
    while(len > 0){
        if(check(len, pi)){
            cout << s.substr(1, len) << '\n';
            return;
        }
        len = pi[len - 1];
    }

    cout << "Just a legend\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
