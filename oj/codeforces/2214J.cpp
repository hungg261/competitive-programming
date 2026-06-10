/******************************************************************************
Link: https://codeforces.com/contest/2214/problem/J
Code: 2214J
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-01-21.57.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string s;
void input(){
    getline(cin,s);
    if(s[0] == 'D'){
        cout<<"Yes";
    }
    else{
        cout<<"Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity.";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    input();

    return 0;
}
