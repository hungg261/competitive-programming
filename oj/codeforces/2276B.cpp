/******************************************************************************
Link: https://codeforces.com/contest/2276/problem/B
Code: 2276B
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-14-21.48.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    pair<int, int> b = {0, 0};
    for(int i = 0; i < n; ++i){
        if(i == n - 1 || s[i] != s[i + 1]){
            if(s[i] == '0') ++b.first;
            else ++b.second;
        }
    }

    set<pair<int, int>> S;
    S.insert(b);

    for(int i = 1; i + 1 < n; ++i){
        pair<int, int> temp = b;
        if(s[i - 1] == s[i + 1]){
            if(s[i] != s[i - 1]){
                --temp.first;
                --temp.second;
            }
            else{
                ++temp.first;
                ++temp.second;
            }
        }

        S.insert(temp);
    }

    cout << (int)S.size() << "\n";
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
