#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000,MAXK=50;
int n,k,a[MAXN+5];
int dp[MAXN+5][MAXK+5];

void solve(){
    dp[1][a[1]%k]=1;
    for(int i=2;i<=n;++i){
        dp[i][a[i]%k]=1;
        for(int j=0;j<k;++j){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            
            int target=((j-a[i])%k+k)%k;
            if(dp[i-1][target]>0){
                dp[i][j]=max(dp[i][j],dp[i-1][target]+1);
            }
        }
    }
    
    // for(int i=1;i<=n;++i){
    //     for(int j=0;j<k;++j){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][0]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
