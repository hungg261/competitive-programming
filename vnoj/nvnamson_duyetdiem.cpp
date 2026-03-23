#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e5+5;
int dp[MAXN+1][2],n,L[MAXN+1],R[MAXN+1];

void solve(){
    // dp[1][0]=R[1]-1+R[1]-L[1];
    // dp[1][1]=R[1]-1;
    
    L[0]=R[0]=1;
    L[n+1]=R[n+1]=n;
    for(int i=1;i<=n+1;++i){
        dp[i][0]=min(   dp[i-1][0]+abs(L[i-1]-R[i])+R[i]-L[i],
                        dp[i-1][1]+abs(R[i-1]-R[i])+R[i]-L[i]);
    
        dp[i][1]=min(   dp[i-1][0]+abs(L[i-1]-L[i])+R[i]-L[i],
                        dp[i-1][1]+abs(R[i-1]-L[i])+R[i]-L[i]);
        
        if(2<=i&&i<=n){
            ++dp[i][0];
            ++dp[i][1];
        }
    }
    
    // for(int i=1;i<=n+1;++i){
    //     cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    // }
    cout<<min(dp[n+1][0],dp[n+1][1])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>L[i]>>R[i];
    }
    
    solve();
    return 0;
}
