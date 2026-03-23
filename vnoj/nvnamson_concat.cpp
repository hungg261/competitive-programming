#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6;
int n,L,R,a[MAXN+5];
int pow10[16]={1};

int cntdigit(int n){
    int res=0;
    while(n>0){
        ++res;
        n/=10;
    }
    return res;
}

void solve(){
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;++i){
        int digit_cnt=cntdigit(a[i]);
        int low=(L-a[i]+pow10[digit_cnt]-1)/pow10[digit_cnt],
            high=(R-a[i])/pow10[digit_cnt];
        
        int idx1=lower_bound(a+1,a+n+1,low)-a,
            idx2=upper_bound(a+1,a+n+1,high)-a-1;
        ans+=idx2-idx1+1;
        // cout<<' '<<a[i]<<' '<<low<<' '<<high<<' '<<idx1<<' '<<idx2<<'\n';
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=1;i<=15;++i){
        pow10[i]=pow10[i-1]*10;
    }
    
    int t;
    cin>>t;
    
    while(t--){
        cin>>n>>L>>R;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        
        solve();
    }
    return 0;
}
