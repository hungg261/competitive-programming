/******************************************************************************
Link: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/A
Code: Group_MWSDmqGsZm_223338A
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-01.30.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;
    cin >> n;

    cout << ((n & (n - 1)) == 0 ? "YES" : "NO") << '\n';

    return 0;
}
