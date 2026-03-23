#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=500;
int a[MAX+5][MAX+5],n,m;
int prefix[MAX+5][MAX+5];

void compute(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            prefix[i][j]=prefix[i][j-1]+a[i][j];
        }
    }
}

int maximum_array_sum(int left,int right){
    int temp=0,ans=-1e18;
    for(int i=1;i<=n;++i){
        int cur=prefix[i][right]-prefix[i][left-1];
        temp=max(temp+cur,cur);
        ans=max(ans,temp);
    }
    
    return ans;
}

void solve(){
    int ans=-1e18;
    for(int left=1;left<=m;++left){
        for(int right=left;right<=m;++right){
            ans=max(ans,maximum_array_sum(left,right));
        }
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    
    compute();
    solve();
    return 0;
}
