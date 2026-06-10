#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1e9+7;

void multiply(int A[2][2],int B[2][2],int res[2][2],const int&mod){
    int temp[2][2]={};
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                (temp[i][j]+=A[i][k]*B[k][j])%=mod;
            }
        }
    }

    memcpy(res,temp,sizeof(temp));
}

void powmod(int a[2][2],int b,int res[2][2],const int&mod){
    int temp[2][2]={{1,0},{0,1}};
    while(b>0){
        if(b%2==1){
            multiply(temp,a,temp,mod);
        }
        multiply(a,a,a,mod);
        b/=2;
    }
    memcpy(res,temp,sizeof(temp));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;

    int base[2][2]={{1,1},{1,0}};

    powmod(base,n+3,base,MOD);
    cout<<((base[0][1]-1)%MOD+MOD)%MOD<<'\n';

    return 0;
}