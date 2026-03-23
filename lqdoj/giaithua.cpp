/******************************************************************************
Link: https://lqdoj.edu.vn/problem/giaithua
Code: giaithua
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-17.41.03
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int A[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        cout<<A[n]<<endl;
    }
    return 0;
}