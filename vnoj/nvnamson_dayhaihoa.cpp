#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int a[MAXN+1],n;

void solve(){
    sort(a+1,a+n+1);
    
    int i=1,
        ans=0;
    for(int j=1;j<=n;++j){
        while(a[j]-a[i]>1){
            ++i;
        }
        
        if(a[j]-a[i]==1){
            ans=max(ans,j-i+1);
        }
    }
    cout<<ans<<'\n';
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
