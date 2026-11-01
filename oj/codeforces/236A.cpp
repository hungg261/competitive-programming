/******************************************************************************
Link: https://codeforces.com/contest/236/problem/A
Code: 236A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-21.21.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    set<char> S;
    for(char c: s)
        S.insert(c);

    cout << ((S.size() & 1) ? "IGNORE HIM!" : "CHAT WITH HER!");

    return 0;
}
