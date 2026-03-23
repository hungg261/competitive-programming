#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6,MAXVAL=1e6;
int a[MAXN+5],n,gcd_cnt[MAXVAL+5],freq[MAXVAL+5];
bool not_prime[MAXVAL+5];

void compute(){
    not_prime[0]=not_prime[1]=true;
    for(int i=2;i*i<=MAXVAL;++i){
        for(int j=i*i;j<=MAXVAL;j+=i){
            not_prime[j]=true;
        }
    }
    
    for(int i=1;i<=n;++i){
        ++freq[a[i]];
    }
}

void solve(){
    compute();
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    // for(int i=1;i<=n;++i){
    //     cerr<<a[i]<<' ';
    // }cerr<<'\n';
    
    for(int i=1;i<=MAXVAL;++i){
        for(int j=i;j<=MAXVAL;j+=i){
            gcd_cnt[i]+=freq[j];
        }
        gcd_cnt[i]*=gcd_cnt[i];
    }
    
    for(int i=MAXVAL;i>=1;--i){
        for(int j=i*2;j<=MAXVAL;j+=i){
            gcd_cnt[i]-=gcd_cnt[j];
        }
    }
    
    // for(int i=2;i<=100;i+=2){
    //     cerr<<i<<": "<<gcd_cnt[i]<<'\n';
    // }
    
    int ans=0;
    for(int i=2;i<=MAXVAL;++i){
        if(!not_prime[i]){
            ans+=gcd_cnt[i];
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
