/******************************************************************************
Link: https://atcoder.jp/contests/awc0185/tasks/awc0185_a
Code: awc0185_a
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-18.00.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a[4];
    cin >> a[1] >> a[2] >> a[3];

    cout << max_element(a + 1, a + 4) - a;

    return 0;
}
