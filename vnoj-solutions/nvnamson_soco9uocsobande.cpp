#include<bits/stdc++.h>
using namespace std;

int pfactor(int n){
    int cnt=1;
    for(int i=2;i*i<=n;++i){
        if(n%i!=0)continue;
        
        int mu=0;
        while(n%i==0){
            n/=i;
            ++mu;
        }
        
        cnt*=mu*2+1;
    }
    if(n>1){
        cnt*=3;
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    
    int ans=0;
    for(int i=1;i*i<=n;++i){
        if(pfactor(i)==9){
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
