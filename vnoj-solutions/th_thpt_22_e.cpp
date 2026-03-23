#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n,x,k,prefix[MAXN+5],arr[MAXN+5];
struct mushroom{
    int X,W;
} a[MAXN+5];

bool cmp(mushroom&u,mushroom&v){
    return u.X<v.X;
}

void solve(){
    int ans=-1e9;
    for(int i=1;i<=n;++i){
        int R=upper_bound(arr+1,arr+n+1,arr[i]+k)-arr-1;
            
        ans=max(ans,prefix[R]-prefix[i-1]);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MARIO.INP","r",stdin);
    freopen("MARIO.OUT","w",stdout);
    cin>>n>>x>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i].X>>a[i].W;
    }
    
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        arr[i]=a[i].X;
        prefix[i]=prefix[i-1]+a[i].W;
    }
    
    solve();
    return 0;
}
