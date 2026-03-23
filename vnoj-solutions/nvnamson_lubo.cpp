#include<bits/stdc++.h>
using namespace std;

const int dx[4]={2,2,1,1},dy[4]={-1,1,-2,2};
const int MAXMN=1e6;
int a[MAXMN+5],n,m;
int dp[MAXMN+5][2];

int get_idx(int i,int j){
    return (i-1)*m+j;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[get_idx(i,j)];
        }
    }
    
    for(int j=1;j<=m;++j){
        dp[get_idx(1,j)][0]=dp[get_idx(1,j)][1]=a[get_idx(1,j)];
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int d=0;d<2;++d){
                int nx=i-dx[d],ny=j-dy[d];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
                    dp[get_idx(i,j)][0]=max(dp[get_idx(i,j)][0],dp[get_idx(nx,ny)][0]+a[get_idx(i,j)]);
                    dp[get_idx(i,j)][1]=max({dp[get_idx(i,j)][1],dp[get_idx(nx,ny)][0]+a[get_idx(i,j)],dp[get_idx(nx,ny)][1]+a[get_idx(i,j)]});
                }
            }
            
            for(int d=2;d<4;++d){
                int nx=i-dx[d],ny=j-dy[d];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
                    dp[get_idx(i,j)][1]=max(dp[get_idx(i,j)][1],dp[get_idx(nx,ny)][0]+a[get_idx(i,j)]);
                }
            }
        }
    }
    
    int ans=0;
    for(int j=1;j<=m;++j){
        ans=max(ans,dp[get_idx(n,j)][1-n%2]);
    }
    
    cout<<n/2<<' '<<ans<<'\n';
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         cout<<dp[get_idx(i,j)][0]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         cerr<<dp[get_idx(i,j)][1]<<' ';
    //     }
    //     cerr<<'\n';
    // }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    
    return 0;
}
