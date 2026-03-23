#include<bits/stdc++.h>
#define int long long
using namespace std;

long long f[3];
void solve(long long A,long long B){
    int ans=0;
    
    f[0]=0,f[1]=1;
    for(int i=0;i<=1;++i){
        if(A<=f[i]&&f[i]<=B)++ans;
    }
    
    while(f[2]<=B){
        f[2]=f[1]+f[0];
        if(A<=f[2]&&f[2]<=B)++ans;
        
        f[0]=f[1];
        f[1]=f[2];
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long A,B;
    cin>>A>>B;
    
    solve(A,B);
    return 0;
}
