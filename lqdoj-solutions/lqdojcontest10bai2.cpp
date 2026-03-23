#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=3e6+1;
bool A[MAX];
void sieve(int R){
    for(int i=2;i<=R;++i)A[i]=1;
    for(int i=2;i*i<=R;++i)
        if(A[i])for(int j=i*i;j<=R;j+=i)
            A[j]=0;
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
    int L,R;cin>>L>>R;
    sieve(R);

    int ans=0;
    for(int i=L;i<=R;++i)
        if(A[i])if(cntdigit(i)%5==0)++ans;

    cout<<ans;
    return 0;
}