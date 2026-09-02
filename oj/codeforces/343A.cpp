/******************************************************************************
Link: https://codeforces.com/contest/343/problem/A
Code: 343A
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-02-14.30.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b;
    cin >> a >> b;

    int res = 0;
    while(b > 0){
        res += a / b;
        a %= b;
        swap(a, b);
    }

    cout << res << "\n";

    return 0;
}
