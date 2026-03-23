/******************************************************************************
Link: https://cses.fi/problemset/task/2413
Code: 2413
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-15-22.04.28
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6,MOD=1e9+7;
int dp[MAXN+1][2];

void solve(){
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=MAXN;++i){
        dp[i][0]=((dp[i-1][0]*4)%MOD+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+(dp[i-1][1]*2)%MOD)%MOD;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("2413.INP","r",stdin);
    //freopen("2413.OUT","w",stdout);
    int t;
    cin>>t;

    solve();
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%MOD<<'\n';
    }
    return 0;
}
