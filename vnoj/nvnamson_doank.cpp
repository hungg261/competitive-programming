#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int n,a[MAXN+5],prefix[MAXN+5];

void solve(){
    int i=1;
    int ans=0;
    for(int j=1;j<=n;++j){
        int sum1=(i+j)*(j-i+1)/2,
            sum2=prefix[j]-prefix[i-1];
            
        if(sum1==sum2){
            i=j+1;
            ++ans;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    
    solve();
    return 0;
}
