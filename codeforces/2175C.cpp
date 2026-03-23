#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;

    int cnt_s[26] = {};
    int cnt_t[26] = {};
    for(int c: s){ ++cnt_s[c - 'a']; }
    for(int c: t){ ++cnt_t[c - 'a']; }

    string origin;
    for(int c = 0; c < 26; ++c){
        if(cnt_s[c] > cnt_t[c]){
            cout << "Impossible\n";
            return;
        }

        origin += string(cnt_t[c] - cnt_s[c], c + 'a');
    }

    string res(origin.size() + s.size(), '?');
    merge(origin.begin(), origin.end(), s.begin(), s.end(), res.begin(), less_equal<char>());

    cout << res << '\n';
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
