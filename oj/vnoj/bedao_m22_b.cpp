#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5,MOD=23;
int a[MAXN+1],n,mark[2][MOD];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    
    long long ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        
        a[i]%=MOD;
        ++mark[1][a[i]];
        if(i>6){
            ++mark[0][a[i-6]];
            ans+=1LL*mark[0][a[i]];
        }
    }
    
    cout<<ans<<'\n';
    return 0;
}
