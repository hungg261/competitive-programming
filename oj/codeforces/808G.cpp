/******************************************************************************
Link: https://codeforces.com/problemset/problem/808/G
Code: 808G
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-26-21.36.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string s, t;
int pi[100005][26];

void solve(){
    string x = t + "#" + s;
    int sz = x.size();

    memset(pi, -0x3f, sizeof pi);

    if(x[0] == '?'){
        for(int c = 0; c < 26; ++c)
            pi[0][c] = 0;
    }
    else{
        pi[0][x[0] - 'a'] = 0;
    }

    for(int i = 1; i < sz; ++i){
        for(char c = 0; c < 26; ++c){
            int j = pi[i - 1][]
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> t;

    solve();

    return 0;
}
