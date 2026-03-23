/******************************************************************************
Link: https://codeforces.com/problemset/problem/1776/L
Code: 1776L
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-10.54.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int p, m, diff;

void solve(){
    int a, b;
    cin >> a >> b;

    if(a == b){
        if(diff == 0) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    if(diff * b % (b - a) == 0){
        int val = diff * b / (b - a);
        if(-m
 <= val && val <= p){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(char c: s){
        if(c == '+') ++p;
        else ++m
;
    }
    diff = p - m;

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
