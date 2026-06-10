#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int a[MAXN+5],n,dp[MAXN+5],len=0;

void solve(){
    dp[len++]=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>dp[len-1]){
            dp[len++]=a[i];
        }
        else{
            *lower_bound(dp,dp+len,a[i])=a[i];
        }
    }
    
    cout<<len<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
