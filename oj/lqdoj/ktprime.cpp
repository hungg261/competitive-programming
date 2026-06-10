#include<bits/stdc++.h>
#define int long long
using namespace std;

bool ktsnt(int n){
    for(int i=2;i*i<=n;++i)
        if(n%i==0)return false;
    return n>1;
}

signed main(){
    int n;cin>>n;
    cout<<(ktsnt(n)?"YES":"NO");
    return 0;
}