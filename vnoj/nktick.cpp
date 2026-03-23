#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=60000;
int n,t[MAXN+1],r[MAXN+1],dp[MAXN+1];

void solve(){
    dp[1]=t[1];
    for(int i=2;i<=n;++i){
        dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
    }

//    for(int i=1;i<=n;++i){
//        cerr<<dp[i]<<' ';
//    }cerr<<'\n';
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
    }
    for(int i=1;i<=n-1;++i){
        cin>>r[i];
    }

    solve();
    return 0;
}
