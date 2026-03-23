#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LONGFN.INP","r",stdin);
    freopen("LONGFN.OUT","w",stdout);
    int n;
    cin>>n;
    
    if(n%2==0){
        cout<<n/2<<'\n';
    }
    else{
        cout<<(n-1)/2-n<<'\n';
    }
    return 0;
}
