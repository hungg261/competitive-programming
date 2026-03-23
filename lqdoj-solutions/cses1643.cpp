#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int a[MAXN+5],n;

int dp[MAXN+5];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    for(int i=1;i<=n;++i){
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }

    // for(int i=1;i<=n;++i){
    //     cout<<dp[i]<<' ';
    // }
    cout<<*max_element(dp+1,dp+n+1)<<'\n';
    return 0;
}