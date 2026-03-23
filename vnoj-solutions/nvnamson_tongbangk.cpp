#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    
    int start=max(1LL,min(k-n,n)),
        end=min(n,k-start),
        len=abs(end-start)+1;
    
    cout<<(len)/2;
    return 0;
}
