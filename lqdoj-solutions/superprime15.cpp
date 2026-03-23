#include<bits/stdc++.h>
#define int long long
using namespace std;

bool ktsnt(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return n>1;
}
string solve(int n){
    while(n>0){
        if(!ktsnt(n))return "KHONG";
        n/=10;
    }
    return "PHAI";
}

signed main(){
    int n;cin>>n;
    if(n>73939133)cout<<"KHONG";
    else cout<<solve(n);

    return 0;
}