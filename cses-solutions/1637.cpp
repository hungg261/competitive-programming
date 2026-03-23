/******************************************************************************
Link: https://cses.fi/problemset/task/1637
Code: 1637
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-11-20.33.28
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int get_largest(int n){
    int res=-1;
    while(n>0){
        res=max(res,n%10);
        n/=10;
    }
    return res;
}

void solve(int n){
    int cnt=0;
    do{
        n-=get_largest(n);
        ++cnt;
    } while(n>0);

    cout<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1637.INP","r",stdin);
    //freopen("1637.OUT","w",stdout);
    int n;
    cin>>n;

    solve(n);
    return 0;
}
