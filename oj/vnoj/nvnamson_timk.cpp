#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int get_div(int i){
    int cnt=0;
    for(int j=i;j<=n;j*=i){
        cnt+=n/j;
        if(j>n/i)break;
    }
    return cnt;
}

void solve(){
    int ans=1e9;
    for(int i=2;i*i<=m;++i){
        if(m%i==0){
            int cnt=0;
            while(m%i==0){
                m/=i;
                ++cnt;
            }
            ans=min(ans,get_div(i)/cnt);
        }
    }
    if(m>1){
        ans=min(ans,get_div(m));
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    
    solve();
    return 0;
}
