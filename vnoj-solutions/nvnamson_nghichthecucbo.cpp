#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4,MAXVAL=1e6,OFFSET=1e6;
int n,k,a[MAXN+1];

void solve(){
    int ans=0;
    unordered_map<int,int>mark;
    for(int i=1;i<=n;++i){
        for(int j=a[i]+1;j<=a[i]+k;++j){
            ans+=mark[j+OFFSET];
        }
        ++mark[a[i]+OFFSET];
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LPERM.INP","r",stdin);
    freopen("LPERM.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
