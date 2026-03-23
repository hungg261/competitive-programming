#include<bits/stdc++.h>
using namespace std;

const int MAXN=100,MAXW=1e5;
long long dp[2][MAXW+1];
int N,W;

void solve(){
    int wi,vi;
    for(int i=1;i<=N;++i){
        cin>>wi>>vi;
        
        for(int j=0;j<=W;++j){
            dp[1][j]=dp[0][j];
            if(j>=wi){
                dp[1][j]=max(dp[1][j],dp[0][j-wi]+vi);
            }
        }
        memcpy(dp[0],dp[1],sizeof dp[0]);
    }
    
    cout<<dp[1][W]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>W;
    solve();
    return 0;
}
