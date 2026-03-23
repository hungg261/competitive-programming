#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

const int MAXN=1000,MAXK=4;
int n,k;
int dp[MAXN+1][MAXK+1][MAXN+1];

void solve(){
    for(int i=1;i<=n;++i){
        dp[i][1][i]=1;
    }
    
    for(int idx=1;idx<=n;++idx){
        for(int chosen=1;chosen<=k;++chosen){
            for(int sum=1;sum<=n;++sum){
                for(int i=idx+1;i<=n-sum;++i){
                    if(chosen+1<=k&&sum+i<=n)dp[i][chosen+1][sum+i]+=dp[idx][chosen][sum];
                }
            }
        }
    }
    
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=k;++j){
    //         cerr<<dp[i][j][n]<<'\t';
    //     }
    //     cerr<<'\n';
    // }
    
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=dp[i][k][n];
        // cout<<dp[i][k][n]<<'\n';
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    solve();
    
    return 0;
}
