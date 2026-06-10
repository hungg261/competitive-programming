#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1e9+7;
int base[2][2]={{1,1},{1,0}};
void matrix_mul(int a[2][2],int b[2][2],int to[2][2],const int MOD=::MOD){
    int temp[2][2];
    // temp[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    // temp[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    // temp[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    // temp[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];

    temp[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
    temp[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
    temp[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
    temp[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
    memcpy(to,temp,sizeof(temp));
}

void power(int a[2][2],int b,int res[2][2]){
    while(b>0){
        if(b%2==1){
            matrix_mul(res,a,res);
        }
        matrix_mul(a,a,a);
        b/=2;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;

    int res[2][2]={{1,0},{0,1}};
    power(base,n,res);

    cout<<res[0][1]<<'\n';
    return 0;
}