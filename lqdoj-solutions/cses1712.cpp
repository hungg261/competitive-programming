#include<bits/stdc++.h>
#define int long long
using namespace std;

int powmod(int a,int b,int m=1e9+6){
    int ans=1;
    while(b>0){
        if(b%2==1)ans=(ans%m*a%m)%m;
        a=(a%m*a%m)%m;
        b/=2;
    }
    return ans;
}

signed main(){
    int t,a,b,c;
    cin>>t;

    while(t--){
        cin>>a>>b>>c;
        cout<<powmod(a,powmod(b,c),1e9+7)<<'\n';
    }
    return 0;
}