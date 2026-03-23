#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6;
int not_prime[MAX+1];

void compute(int n){
    not_prime[0]=not_prime[1]=true;
    for(int i=2;i*i<=n;++i){
        if(!not_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                not_prime[j]=true;
            }
        }
    }
}

void solve(int n){
    int ans=0;
    for(int i=2;i<=n/2;++i){
        if(!not_prime[i]&&!not_prime[n-i])++ans;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GOL.INP","r",stdin);
    freopen("GOL.OUT","w",stdout);
    int n;
    cin>>n;
    
    compute(n);
    solve(n);
    return 0;
}
