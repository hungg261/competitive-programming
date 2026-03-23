#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LONGK.INP","r",stdin);
    freopen("LONGK.OUT","w",stdout);
    int n;
    cin>>n;
    
    vector<int>a(n),mark(n+1,0);
    int ans=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        
        ans+=mark[a[i]];
        ++mark[a[i]];
    }
    
    for(int i=0;i<n;++i){
        cout<<ans-mark[a[i]]*(mark[a[i]]-1)/2+(mark[a[i]]-1)*(mark[a[i]]-2)/2<<'\n';
    }
    return 0;
}
