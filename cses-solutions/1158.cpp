/******************************************************************************
Link: https://cses.fi/problemset/task/1158
Code: 1158
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-11-23.16.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1000,MAXVAL=1e5;
int h[MAX+1],s[MAX+1],n,x,dp[MAX+1][MAXVAL+1];

void solve(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=x;++j){
            if(j>=h[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i]]+s[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][x]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
//    freopen("1158.INP","r",stdin);
//    freopen("1158.OUT","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;++i)cin>>h[i];
    for(int i=1;i<=n;++i)cin>>s[i];

    solve();
    return 0;
}
