#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=3e5;
int n,k;
struct item{
    int m,v;
} a[MAXN+5];
multiset<int>c;

bool cmp(item&u,item&v){
    if(u.v==v.v)return u.m<v.m;
    return u.v>v.v;
}

void solve(){
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;++i){
        auto pos=c.lower_bound(a[i].m);
        if(pos!=c.end()){
            ans+=a[i].v;
            c.erase(pos);
        }
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i].m>>a[i].v;
    }
    for(int i=1;i<=k;++i){
        int cur;
        cin>>cur;
        
        c.insert(cur);
    }
    
    solve();
    return 0;
}
