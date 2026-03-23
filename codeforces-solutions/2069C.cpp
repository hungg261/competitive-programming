#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6,MOD=998244353;
int a[MAXN+1],n,dp[MAXN+1][3];

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    for(int i=1;i<=n;++i){
        memcpy(dp[i],dp[i-1],sizeof dp[i]);
        if(a[i]==1){
            ++dp[i][0];
        }
        else if(a[i]==2){
            (dp[i][1]+=(dp[i-1][1]+dp[i][0])%MOD)%=MOD;
        }
        else{
            (dp[i][2]+=dp[i-1][1])%=MOD;
        }
    }

    cout<<dp[n][2]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
