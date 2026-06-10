#include<bits/stdc++.h>
// memory efficient?!
using namespace std;

const int MAXN=1e6;
int maxdiv[MAXN+1],mu[MAXN+1];
int res[MAXN+1]={1};

void compute(){
    for(int i=2;i*i<=MAXN;++i){
        if(maxdiv[i]==0){
            for(int j=i*i;j<=MAXN;j+=i){
                maxdiv[j]=i;
            }
        }
    }
}

void pfactor(int n){
    int pos=n;
    res[pos]=res[pos-1];
    while(n>1){
        int prime=maxdiv[n];
        if(prime==0){
            prime=n;
        }
        
        int cnt=0;
        while(n%prime==0){
            n/=prime;
            ++cnt;
        }
        
        if(cnt>mu[prime]){
            res[pos]*=prime*(cnt-mu[prime]);
            while(res[pos]%10==0){
                res[pos]/=10;
            }
            res[pos]%=100;
            
            mu[prime]=cnt;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    compute();
    for(int i=1;i<=MAXN;++i){
        pfactor(i);
    }
    
    int n;
    while(cin>>n){
        cout<<res[n]%10<<'\n';
    }
    return 0;
}
