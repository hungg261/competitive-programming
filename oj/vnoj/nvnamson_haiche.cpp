#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int m,k,n,prefix[MAXN+5];

void solve(){
    int target=m*k;
    int ans=1e9;
    for(int low=0;low<=n;++low){
        int high=lower_bound(prefix+low,prefix+n+1,prefix[low]+target)-prefix;
        
        if(prefix[high]-prefix[low]>=target){
            ans=min(ans,high-low);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>k>>n;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        prefix[i]=prefix[i-1]+cur;
    }
    
    solve();
    return 0;
}
