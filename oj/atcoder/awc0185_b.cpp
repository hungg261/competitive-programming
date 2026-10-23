/******************************************************************************
Link: https://atcoder.jp/contests/awc0185/tasks/awc0185_b
Code: awc0185_b
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-18.02.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s[n];
    for(int i = 0; i < n; ++i) cin >> s[i];

    for(int i = 0; i < n; ++i){
        cout << count(begin(s[i]), end(s[i]), '.') << "\n";
    }

    return 0;
}
