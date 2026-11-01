/******************************************************************************
Link: https://codeforces.com/contest/112/problem/A
Code: 112A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-22.21.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < (int)s1.size(); ++i){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    if(s1 < s2) cout << -1;
    else if (s1 > s2) cout << 1;
    else cout << 0;

    return 0;
}
