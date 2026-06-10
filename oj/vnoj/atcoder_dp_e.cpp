#include<bits/stdc++.h>
using namespace std;

const int MAXN=100,MAXW=1e9,MAXV=1e5;
int n,weight;
long long dp[2][MAXV+1];

void solve(){
    // dp[i][j] la khoi luong nho nhat sao cho chon duoc do co gia tri j sau i phan tu dau tien
    memset(dp,1,sizeof dp);
    
    dp[0][0]=0;
    int w,v;
    for(int i=1;i<n;++i){
        cin>>w>>v;
        for(int j=0;j<=MAXV;++j){
            dp[1][j]=dp[0][j];
            if(j>=v){
                dp[1][j]=min(dp[1][j],dp[0][j-v]+w);
            }
        }
        memcpy(dp[0],dp[1],sizeof dp[0]);
    }
    
    
    cin>>w>>v;
    for(int j=MAXV;j>=0;--j){
        dp[1][j]=dp[0][j];
        if(j>=v){
            dp[1][j]=min(dp[1][j],dp[0][j-v]+w);
        }
        
        if(dp[1][j]<=weight){
            cout<<j<<'\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>weight;
    solve();
    return 0;
}
