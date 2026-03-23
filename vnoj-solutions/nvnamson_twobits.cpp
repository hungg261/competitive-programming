#include<bits/stdc++.h>
using namespace std;

int lg(long long n){
    int res=0;
    while(n>1){
        n/=2;
        ++res;
    }
    return res;
}

const int MOD=1e9+7;
void solve(){
    long long n;
    cin>>n;
    
    int high=lg(n-1);
    long long ans=0;
    for(int i=high;i>=0;--i){
        long long cur=1LL<<i;
        
        int res=lg(n-cur);
        if(i<=res)--res;
        (ans+=(cur%MOD*(res+1)%MOD))%=MOD;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
    cin>>t;
    while(t--){
        solve();
    }
}
