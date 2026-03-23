/******************************************************************************
Link: https://cses.fi/problemset/task/1634
Code: 1634
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-10-00.13.36
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=100, MAXVAL=1e6;
int n,a[MAX+5],x,dp[MAXVAL+5];

void solve(){
    memset(dp,1,sizeof dp);
    dp[0]=0;

    for(int i=1;i<=x;++i){
        for(int j=1;j<=n;++j){
            if(i>=a[j]){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    cout<<(dp[x]==dp[MAXVAL+1]?-1:dp[x])<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1634.INP","r",stdin);
    //freopen("1634.OUT","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
