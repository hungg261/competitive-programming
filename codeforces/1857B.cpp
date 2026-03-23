#include<bits/stdc++.h>
using namespace std;

void solve(){
    string S;
    cin >> S;

    S = "0" + S;

    int n = S.size();
    int k = n;
    for(int i = n - 2; i >= 0; --i){
        if(S[i + 1] >= '5'){
            for(; S[i] == '9'; --i){}
            S[i]++;

            k = i;
        }
    }

    for(int i = k + 1; i < n; ++i){ S[i] = '0'; }
    for(int i = 0; i < n; ++i){
        if(S[i] != '0'){
            cout << S.substr(i) << '\n';
            return;
        }
    }

    cout << S << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
