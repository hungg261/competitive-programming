#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1000005;
int n,k,prime[78500],len=0;
bool Q[MAX+1];

void compute(){
    Q[0]=Q[1]=true;
    int n=min(MAX,::n);
    for(int i=2;i*i<=n;++i){
        if(!Q[i]){
            for(int j=i*i;j<=n;j+=i){
                Q[j]=true;
            }
        }
    }
    
    for(int i=2;i<=n;++i){
        if(!Q[i]){
            prime[len++]=i;
        }
    }
}

int power(int a,int b){
    int res=1;
    while(b>0){
        if(b%2==1){
            res*=a;
        }
        a*=a;
        b/=2;
    }
    return res;
}

void solve(){
    int ans=-1;
    for(int i=1;i<len-1;++i){
        int p1=prime[i-1],
            p2=prime[i],
            p3=prime[i+1];
        
        int pp1,pp2,pp3;
        for(int t1=1;(pp1=power(p1,t1))<=n;++t1){
            if(pp1<0)break;
            for(int t2=1;pp1<=n/(pp2=power(p2,t2));++t2){
                if(pp1*pp2<0)break;
                for(int t3=1;pp1*pp2<=n/(pp3=power(p3,t3));++t3){
                    if(pp1*pp2*pp3<0)break;
                    int m=pp1*pp2*pp3;
                    if(m>n)break;
                    
                    int divcnt=(t1+1)*(t2+1)*(t3+1);
                    if(divcnt==k){
                        ans=max(ans,m);
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    compute();
    solve();
    
    return 0;
}
