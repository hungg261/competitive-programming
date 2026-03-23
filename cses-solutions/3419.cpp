/******************************************************************************
Link: https://cses.fi/problemset/task/3419
Code: 3419
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-24-09.41.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("3419.INP","r",stdin);
    //freopen("3419.OUT","w",stdout);
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << (i ^ j) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
