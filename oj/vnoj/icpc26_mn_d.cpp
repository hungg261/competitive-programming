/******************************************************************************
Link: https://oj.vnoi.info/problem/icpc26_mn_d
Code: icpc26_mn_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-16.47.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;


int counter(string s){
    int low = 0, high = (int)s.size() - 1;
    int res = 0;
    while(low < high){
        ++res;
        if(s[low] != s[high]) break;
        ++low;
        --high;
    }
    return res;
}

string s;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int n = (int)s.size();

    int cnt[26] = {};
    int dfc = 0;
    for(int c: s){
        c -= 'A';
        if(cnt[c]++ == 0){
            ++dfc;
        }
    }

    if(dfc == 1){
        cout << "-1\n";
        return 0;
    }

    int pairs = 0, odd = 0;
    for(int i = 0; i < 26; ++i){
        pairs += cnt[i] / 2;
        if(cnt[i] % 2 == 1){
            ++odd;
        }
    }

    int ans;
    if(odd >= 2) ans = pairs + 1;
    else if(odd == 1) ans = pairs;
    else ans = pairs - 1;

    cout << ans << "\n";

    return 0;
}
