#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n,a[MAXN+1],dp[MAXN+1];

void solve(){
    dp[1]=max(0LL,a[1]);
    dp[2]=max({0LL,dp[1],dp[1]+a[2],a[2]});
    for(int i=3;i<=n;++i){
        dp[i]=max({dp[i-1],dp[i-3]+a[i-1]+a[i],dp[i-2]+a[i],a[i],0LL});
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
