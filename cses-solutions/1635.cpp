/******************************************************************************
Link: https://cses.fi/problemset/task/1635
Code: 1635
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-10-00.19.27
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100,MAXVAL=1e6, MOD=1e9+7;
int dp[MAXVAL+5],n,a[MAXN+5],x;
void solve(){
    dp[0]=1;
    for(int i=1;i<=x;++i){
        for(int j=1;j<=n;++j){
            if(i>=a[j]){
                dp[i]=(dp[i]+dp[i-a[j]])%MOD;
            }
        }
    }
    cout<<dp[x]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1635.INP","r",stdin);
    //freopen("1635.OUT","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
