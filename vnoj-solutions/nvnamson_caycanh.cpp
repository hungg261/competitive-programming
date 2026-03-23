#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5;
int n,a[MAX+1];

int dp[MAX+1];
int solve(){
    int len=0;
    dp[len++]=a[0];
    for(int i=1;i<n;++i){
        if(dp[len-1]<a[i]){
            dp[len++]=a[i];
        }
        else *lower_bound(dp,dp+len,a[i])=a[i];
    }
    return len;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    
    int ans=solve();
    for(int i=0;i<n;++i){
        a[i]=-a[i];
    }
    ans=max(ans,solve());
    cout<<n-ans<<'\n';
    return 0;
}
