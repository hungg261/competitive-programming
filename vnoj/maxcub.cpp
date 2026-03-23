#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=30;
int n,arr[MAXN+1][MAXN+1][MAXN+1],prefix[MAXN+1][MAXN+1][MAXN+1];

void compute(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                prefix[i][j][k]=prefix[i][j-1][k]+prefix[i][j][k-1]-prefix[i][j-1][k-1]+prefix[i-1][j][k]-prefix[i-1][j-1][k]-prefix[i-1][j][k-1]+prefix[i-1][j-1][k-1]+arr[i][j][k];
            }
        }
    }
}

int get(int x1,int y1,int z1,int x2,int y2,int z2){
    return prefix[x2][y2][z2]-(prefix[x2][y1-1][z2]+prefix[x2][y2][z1-1]-prefix[x2][y1-1][z1-1]+prefix[x1-1][y2][z2]-prefix[x1-1][y1-1][z2]-prefix[x1-1][y2][z1-1]+prefix[x1-1][y1-1][z1-1]);
}

void solve(){
    compute();
    int ans=-1e18;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                for(int len=1;i+len-1<=n&&j+len-1<=n&&k+len-1<=n;++len){
                    ans=max(ans,get(i,j,k,i+len-1,j+len-1,k+len-1));
                }
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    cin>>arr[i][j][k];
                }
            }
        }
        
        solve();
    }
    return 0;
}
