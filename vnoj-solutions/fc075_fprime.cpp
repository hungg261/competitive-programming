#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e7;
bool not_prime[MAXN+5];

void compute(){
    not_prime[0]=not_prime[1]=true;
    for(int i=2;i*i<=MAXN;++i){
        if(!not_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                not_prime[j]=true;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int K;
    cin>>K;
    
    compute();
    while(K--){
        int N;
        cin>>N;
        
        cout<<(N>=2&&!not_prime[N] ? "YES\n":"NO\n");
    }
    return 0;
}
