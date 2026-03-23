#include<bits/stdc++.h>
#define int long long
using namespace std;

int powmod(int a,int b,int m){
    int res=1;
    a%=m;
    
    while(b>0){
        if(b&1){
            (res*=a)%=m;
        }
        (a*=a)%=m;
        b>>=1;
    }
    return res;
}

int solve(int a,int b,int k){
    return (a*powmod(10,k-1,b)*10)/b %10;
}

int a,b,k,p;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>k>>p;

    for(int digit=k;digit<k+p;++digit){
        cout<<solve(a,b,digit);
    }
    cout<<'\n';
    return 0;
}
