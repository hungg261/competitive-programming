/******************************************************************************
Link: https://cses.fi/problemset/task/1068
Code: 1068
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-27-00.38.30
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1068.INP","r",stdin);
    //freopen("1068.OUT","w",stdout);

    int n;
    cin >> n;

    while (n > 1){
        cout << n << ' ';
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n = n * 3 + 1;
        }
    }
    cout << n << '\n';

    return 0;
}
