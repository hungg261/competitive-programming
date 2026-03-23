#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int dp[2][2],n;

void solve(){
    dp[0][0]=dp[0][1]=-1e18;
    int cur;
    for(int i=1;i<=n;++i){
        cin>>cur;
        dp[1][0]=max({dp[0][0],dp[0][1]+cur,cur});
        dp[1][1]=max(dp[0][1],dp[0][0]-cur);
        
        memcpy(dp[0],dp[1],sizeof(dp[0]));
    }
    
    cout<<*max_element(dp[1],dp[1]+2)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    solve();
    
    return 0;
}
