/******************************************************************************
Link: https://cses.fi/problemset/task/1636
Code: 1636
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-10-00.26.33
*******************************************************************************/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

const int MAX=100,MAXVAL=1e6,MOD=1e9+7;
int a[MAX+5],n,x,dp[MAX+1][MAXVAL+1];

void solve(){
    int cur;
    for(int j=0;j<=n;++j)dp[j][0]=1;
    for(int i=1;i<=x;++i){
        for(int j=1;j<=n;++j){
            cur=0;
            if(i>=a[j]){
                (cur+=dp[j][i-a[j]])%=MOD;
                dp[j][i]=(dp[j-1][i]+cur)%MOD;
            }
            else dp[j][i]=dp[j-1][i];
        }
    }

//    for(int i=0;i<=x;++i){
//        for(int j=0;j<=n;++j){
//            cerr<<dp[i][j]<<' ';
//        }
//        cerr<<'\n';
//    }
    cout<<dp[n][x]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1636.INP","r",stdin);
    //freopen("1636.OUT","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    solve();
    return 0;
}
