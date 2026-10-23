/******************************************************************************
Link: https://atcoder.jp/contests/abc479/tasks/abc479_a
Code: abc479_a
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-14.23.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        if(i & 1) res += cur;
    }

    cout << res << "\n";

    return 0;
}
