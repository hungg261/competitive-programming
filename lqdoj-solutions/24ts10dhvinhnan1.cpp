#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
bool A[MAX]={};

void sieve(int n){
    for(int i=2;i*i<=n;++i)
        if(!A[i])for(int j=i*i;j<=n;j+=i)
            A[j]=1;
}

int cntdigit(int n){
    int r=0;
    while(n>0){
        r+=n%10;
        n/=10;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int L,R;cin>>L>>R;
    if(L>R||L<=1||R>1e6){
        cout<<-1;
        return 0;
    }
    sieve(R);

    int cnt=0;
    for(int i=max(2LL,L);i<=R;++i)
        if(!A[i])if(!A[cntdigit(i)])++cnt;
    cout<<cnt;
    return 0;
}