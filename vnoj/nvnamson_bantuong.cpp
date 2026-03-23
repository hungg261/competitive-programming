#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2000;
int n,a[MAXN+5];

int dp[MAXN+5][MAXN+5];
void solve(){
    for(int i=1;i<=n;++i){
        dp[i][i]=a[i]*n;
    }
    
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            
            dp[i][j]=max(dp[i][j-1]+a[j]*(n-len+1),dp[i+1][j]+a[i]*(n-len+1));
        }
    }
    
    cout<<dp[1][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
