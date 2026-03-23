#include<bits/stdc++.h>
#define cerr if(false)cerr
#define int long long
using namespace std;

const int MAX=1e5,MOD=1e9+7;
int n,q,a[MAX+1],save[MAX+1],divisor[MAX+1];
int ans=1;

int powmod(int a,int b){
    int res=1;
    while(b>0){
        if(b%2==1)(res*=a)%=MOD;
        (a*=a)%=MOD;
        b/=2;
    }
    return res;
}

void sieve(){
    for(int i=2;i*i<=MAX;++i){
        if(divisor[i]==0){
            for(int j=i*i;j<=MAX;j+=i){
                divisor[j]=i;
            }
        }
    }
}

void add(int n){
    while(n>1){
        int p=divisor[n];
        if(p==0)p=n;
        
        int cnt=0;
        while(n%p==0){
            n/=p;
            ++cnt;
        }
        
        (ans*=powmod(save[p]+1,MOD-2))%=MOD;
        save[p]+=cnt;
        (ans*=save[p]+1)%=MOD;
    }
}

void subtract(int n){
    cerr<<"n: "<<n<<"\n";
    while(n>1){
        int p=divisor[n];
        if(p==0)p=n;
        
        int cnt=0;
        while(n%p==0){
            n/=p;
            ++cnt;
        }
        
        (ans*=powmod(save[p]+1,MOD-2))%=MOD;
        save[p]-=cnt;
        cerr<<ans<<' '<<p<<' '<<cnt<<'\n';
        (ans*=save[p]+1)%=MOD;
    }
}



void query(){
    int x,y;
    cin>>x>>y;
    
    subtract(a[x]);
    cerr<<ans<<'\n';
    add(y);
    cerr<<ans<<"\n\n";
    a[x]=y;
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    fill(a+1,a+n+1,1);
    sieve();
    
    while(q--){
        query();
    }
    return 0;
}
