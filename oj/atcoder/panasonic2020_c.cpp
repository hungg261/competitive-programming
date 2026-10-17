/******************************************************************************
Link: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
Code: panasonic2020_c
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-17-20.42.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int d = c - a - b;
    if(d < 0) cout << "No\n";
    else cout << (d * d > 4 * a * b ? "Yes\n" : "No\n");

    return 0;
}
