#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1;
int A[MAX],k=0;

void sieve(int R){
    for(int i=1;i<=R;++i)A[i]=1;
    for(int i=2;i<=R;++i){
        if(A[i]==1){
            for(int j=i;j<=R;j+=i){
                int c=0,r=j;
                while(r%i==0){
                    r/=i;
                    ++c;
                }
                A[j]*=c+1;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int L,R;cin>>L>>R;
    sieve(R);

    cout<<"0\n";
    for(int i=L;i<=R;++i){
        cout<<2*A[i]<<' ';
    }
    return 0;
}