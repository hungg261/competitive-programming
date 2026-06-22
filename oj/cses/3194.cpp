/******************************************************************************
Link: https://cses.fi/problemset/task/3194
Code: 3194
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-17-18.13.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, a[MAXN + 5];

void sus(int n){
    for(int i = 0; i <= 50; ++i){
        if(i < n){
            cerr << "x";
            continue;
        }
//        cerr << i << ": " << ((i & n) == n) << endl;
        cerr << ((i & n) == n) << "";
    }
    cerr << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

//    cin >> n;

    for(int n = 0; n <= 10; ++n) sus(n);

    return 0;
}
