/******************************************************************************
Link: https://lqdoj.edu.vn/problem/fibo00
Code: fibo00
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-12-09.43.06
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

const int MAX=90;
int A[MAX];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    A[0]=A[1]=1;

    for(int i=2;i<n;++i)A[i]=A[i-1]+A[i-2];
    for(int i=0;i<n;++i)cout<<A[i]<<' ';
    return 0;
}