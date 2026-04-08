/******************************************************************************
Link: https://cses.fi/problemset/task/3112
Code: 3112
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-08-19.01.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int LIMIT = 30;
void solve(){
    int l = 1, r = 1e9;
    int turn = 0;
    while(l < r){
        if(++turn > LIMIT) exit(-1);

        int mid = (l + r) >> 1;
        cout << "? " << mid << endl;

        string status;
        cin >> status;

        if(status == "YES") l = mid + 1;
        else if(status == "NO") r = mid;
    }

    cout << "! " << l << endl;
}

signed main(){

    solve();

    return 0;
}
