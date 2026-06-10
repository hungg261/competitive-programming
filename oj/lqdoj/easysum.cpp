#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;cin>>n;

    // int a=(n+1)/2,b=n/2;
    // cout<<a*a-b*(b+1);

    if(n%2==0)cout<<-n/2;
    else cout<<n-n/2;
    return 0;
}