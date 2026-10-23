/******************************************************************************
Link: https://codeforces.com/contest/158/problem/A
Code: 158A
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-23-13.55.26
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] > 0 && a[i] >= a[k]) ++res;
    }

    cout << res << "\n";

    return 0;
}
