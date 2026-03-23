#include<bits/stdc++.h>
#define int long long
#define umap unordered_map
using namespace std;

const int MOD=1e9+7;
auto pfactor(int n){
    umap<int,int>A;
    int c=0;
    while(n%2==0)n/=2,++c;
    if(c)A[2]+=c;

    for(int i=3;i*i<=n;i+=2){
        c=0;
        while(n%i==0)n/=i,++c;
        if(c)A[i]+=c;
    }
    if(n>1)++A[n];

    return A;
}

int power(int a,int b){
    int r=1;
    while(b>0){
        if(b%2==1)r=(r%MOD*a%MOD)%MOD;
        a=(a%MOD*a%MOD)%MOD;
        b/=2;
    }
    return r%MOD;
}

signed main(){
    int n;cin>>n;
    umap<int,int>Q;
    for(int i=0,q;i<n;++i){
        cin>>q;
        auto S=pfactor(q);
        for(auto p:S){
            Q[p.first]=max(Q[p.first],p.second);
        }
    }

    int ans=1;
    for(auto p:Q)
        ans=(ans%MOD*power(p.first,p.second+p.second%2))%MOD;
    cout<<ans;
    return 0;
}