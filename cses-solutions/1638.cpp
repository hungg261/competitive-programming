/******************************************************************************
Link: https://cses.fi/problemset/task/1638
Code: 1638
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-11-20.55.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1000, MOD=1e9+7;
int n,dp[MAX+1][MAX+1];
bool a[MAX+1][MAX+1];

void solve(){
    dp[1][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]){
                (dp[i][j]+=(dp[i-1][j]+dp[i][j-1]))%=MOD;
            }
        }
    }

    cout<<dp[n][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1638.INP","r",stdin);
    //freopen("1638.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        string line;
        cin>>line;

        for(int j=1;j<=n;++j){
            a[i][j]=line[j-1]=='.';
        }
    }

    solve();
    return 0;
}
