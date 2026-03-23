/******************************************************************************
Link: https://cses.fi/problemset/task/1633
Code: 1633
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-10-00.06.49
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6, MOD=1e9+7;
int dp[MAX+5],n;

void solve(){
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=6;++j){
            if(i>=j){
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1633.INP","r",stdin);
    //freopen("1633.OUT","w",stdout);
    cin>>n;

    solve();
    return 0;
}
