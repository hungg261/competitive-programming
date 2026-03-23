#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int n,k,a[MAXN+5],prefix[MAXN+5];
int temp[MAXN+5];
int Q[MAXN+5];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefix[i]=temp[i]=((prefix[i-1]+a[i])%k+k)%k;
    }
    
    sort(temp,temp+n+1);
    Q[0]=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        prefix[i]=lower_bound(temp,temp+n+1,prefix[i])-temp;
        
        ans+=Q[prefix[i]];
        ++Q[prefix[i]];
    }
    
    cout<<ans<<'\n';
    return 0;
}
