#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1e9+7;
int power(int a,int b){
    int ans=1;
    while(b>0){
        if(b%2==1)ans=(ans%MOD*a%MOD)%MOD;
        a=(a%MOD*a%MOD)%MOD;
        b>>=1;
    }
    return ans;
}

signed main(){
    int n;cin>>n;
    cout<<power(2,n);
    return 0;
}