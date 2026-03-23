#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int n,B[MAXN+1],A[MAXN+1];
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>B[i];
    }
    
    A[1]=B[1];
    int sum=B[1];
    for(int i=2;i<=n;++i){
        A[i]=B[i]*i-sum;
        sum+=A[i];
    }
    
    for(int i=1;i<=n;++i){
        cout<<A[i]<<' ';
    }
    return 0;
}
