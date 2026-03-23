#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int a[MAXN+5],n,q,prefix[MAXN+5];

void query(int l,int r){
    int idx=upper_bound(prefix+l,prefix+r+1,(prefix[l-1]+prefix[r])/2)-prefix;
    
    int ans1=llabs(prefix[l-1]+prefix[r]-2*prefix[idx]),
        ans2=llabs(prefix[l-1]+prefix[r]-2*prefix[idx-1]);
    cout<<min(ans1,ans2)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    
    while(q--){
        int l,r;
        cin>>l>>r;
        
        query(l,r);
    }
    return 0;
}
