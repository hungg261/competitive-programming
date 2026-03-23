#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6, MOD=1e9+7;
int divisor[MAX+1],factor[MAX+1];

void compute(int n){
    for(int i=2;i*i<=n;++i){
        if(divisor[i]==0){
            for(int j=i*i;j<=n;j+=i){
                divisor[j]=i;
            }
        }
    }
}

void pfactor(int n){
    while(n>1){
        int p=divisor[n];
        if(p==0)p=n;
        
        int mu=0;
        while(n%p==0){
            n/=p;
            ++mu;
        }
        factor[p]=max(factor[p],mu);
    }
}

int powmod(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)(res*=a)%=MOD;
        (a*=a)%=MOD;
        b>>=1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LCM.INP","r",stdin);
    freopen("LCM.OUT","w",stdout);
    int n;
    cin>>n;
    
    compute(n);
    for(int i=2;i<=n;++i){
        pfactor(i);
    }
    
    int ans=1;
    for(int i=2;i<=n;++i){
        (ans*=powmod(i,factor[i]))%=MOD;
    }
    cout<<ans<<'\n';
    return 0;
}
