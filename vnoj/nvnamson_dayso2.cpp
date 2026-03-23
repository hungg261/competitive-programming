#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[100005],P[100005];
void solve(){
    unordered_map<int,int>Q;
    int ans=-1e18;
    for(int i=1;i<=n;++i){
        if(Q.count(a[i]))ans=max(ans,P[i]-Q[a[i]]);
        
        if(Q.count(a[i]))Q[a[i]]=min(Q[a[i]],P[i-1]);
        else Q[a[i]]=P[i-1];
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        P[i]=P[i-1]+a[i];
    }
    
    solve();
    return 0;
}
