#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

const int MAXN=1e5;
int a[MAXN+5],prefix[MAXN+5],minpre[MAXN+5],maxpre[MAXN+5],n,q;

void compute(){
    minpre[0]=prefix[0];
    for(int i=1;i<=n;++i){
        minpre[i]=min(minpre[i-1],prefix[i]);
    }
    
    maxpre[n]=prefix[n];
    for(int i=n-1;i>=0;--i){
        maxpre[i]=max(maxpre[i+1],prefix[i]);
    }
}

void solve(){
    int l,r;
    cin>>l>>r;
    
    cout<<maxpre[r]-minpre[l-1]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LONGMAX.INP","r",stdin);
    freopen("LONGMAX.OUT","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    compute();
    
    while(q--){
        solve();
    }
    return 0;
}
