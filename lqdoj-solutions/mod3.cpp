#include<bits/stdc++.h>
using namespace std;

signed main(){
    long long a,b,c;
    cin>>a>>b>>c;

    long long res=0;
    while(b>0){
        if(b%2==1)res=(res+a)%c;
        a=(a+a)%c;
        b/=2;
    }
    cout<<res<<'\n';
    return 0;
}