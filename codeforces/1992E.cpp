/******************************************************************************
Link: https://codeforces.com/problemset/problem/1992/E
Code: 1992E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-21.46.00
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string mul(const string& a, int len){
    string res;
    for(int i = 1; i <= len; ++i) res += a;
    return res;
}

void solve(){
    int n;
    cin >> n;

    string s_n = to_string(n);
    int sz = s_n.size();
    string total = mul(s_n, 10000);
    for(int a = 1; a <= 10000; ++a){
        for(int b = 1; b <= min(10000, a * sz); ++b){
            string cur = total.substr(a * sz - b);
            string target = to_string(a * n - b);

            if(cur == target){
                cerr << a << ' ' << b << '\n';
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
