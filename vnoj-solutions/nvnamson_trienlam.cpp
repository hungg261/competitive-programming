#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=5e5;
int n;
struct item{
    int size,value;
} a[MAXN+5];

bool cmp(item&u,item&v){
    if(u.size==v.size)return u.value<v.value;
    return u.size<v.size;
}

void solve(){
    sort(a+1,a+n+1,cmp);
    int minsum=1e18;
    int prefix=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        minsum=min(minsum,prefix-a[i].size);
        prefix+=a[i].value;
        ans=max(ans,(prefix-a[i].size)-minsum);
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].size>>a[i].value;
    }
    
    solve();
    return 0;
}
