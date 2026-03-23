#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,k,d;
    cin>>n>>k>>d;
    
    cout<<n/(d/__gcd(k,d))<<'\n';
    return 0;
}
