#include<bits/stdc++.h>
using namespace std;

signed main(){
    long long a,b,c=1e9+7;
    cin>>a>>b;

    long long res=1;
    a%=c;
    while(b>0){
        if(b%2==1)res=(res*a)%c;
        a=(a*a)%c;
        b/=2;
    }
    cout<<res<<'\n';
    return 0;
}