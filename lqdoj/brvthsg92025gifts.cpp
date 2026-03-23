#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    int a,b;
    cin>>a>>b;

    int n=__gcd(a,b);
    int ans=0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            if(i*i==n)++ans;
            else ans+=2;
        }
    }

    cout<<ans<<'\n';
    return 0;
}