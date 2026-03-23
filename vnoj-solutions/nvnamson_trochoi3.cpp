#include<bits/stdc++.h>
#define new sussy
#define int long long
using namespace std;

const int MAXN=1e6,MAXVAL=1e6;
int n,freq[MAXVAL+5],maxdiv[MAXVAL+5];
int chan=0,le=0;

void compute(){
    for(int i=2;i*i<=MAXVAL;++i){
        if(maxdiv[i]==0){
            for(int j=i*i;j<=MAXVAL;j+=i){
                maxdiv[j]=i;
            }
        }
    }
}

void pfactor(int n){
    while(n>1){
        int p=maxdiv[n];
        if(p==0)p=n;
        
        int old=freq[p];
        while(n%p==0){
            n/=p;
            ++freq[p];
        }
        int new=freq[p];
        
        if(new%2!=old%2){
            if(new%2==0){
                ++chan;
                --le;
            }
            else{
                ++le;
                --chan;
            }
        }
        chan=max(0LL,chan);
        le=max(0LL,le);
    }
}

vector<bool>res;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    compute();
    cin>>n;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        pfactor(cur);
        res.push_back(le==0);
    }
    
    cout<<count(begin(res),end(res),true)<<'\n';
    for(bool ele:res){
        cout<<(ele?"YES":"NO")<<' ';
    }
    return 0;
}
