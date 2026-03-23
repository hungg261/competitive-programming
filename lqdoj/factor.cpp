#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n){
    int ans=1,c=0;
    while(n%2==0){
        n/=2,++c;
        cout<<2;
        if(n>1)cout<<"*";
    }
    ans*=c+1;

    for(int i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0){
            n/=i,++c;
            cout<<i;
            if(n>1)cout<<"*";
        }
        ans*=c+1;
    }
    if(n>1){
        ans*=2;
        cout<<n;
    }
    cout<<'\n'<<ans;
}

signed main(){
    int n;cin>>n;
    solve(n);
    return 0;
}