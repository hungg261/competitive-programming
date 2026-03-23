#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

const int MAXN=1e6;
int hash[MAXN+5],powhash[MAXN+5];
string s,t;
int n,m;

int getTotalHash(int BASE,int MOD){
    int hashy=0;
    for(int i=1;i<=m;++i){
        hashy=(hashy*BASE+(t[i]-'a'+1))%MOD;
    }
    return hashy;
}

void compute(int BASE,int MOD){
    powhash[0]=1;
    for(int i=1;i<=n;++i){
        powhash[i]=(powhash[i-1]*BASE)%MOD;
    }
    
    for(int i=1;i<=n;++i){
        hash[i]=(hash[i-1]*BASE+(s[i]-'a'+1))%MOD;
    }
}

int getHash(int i,int j,int MOD){
    return ((hash[j]-hash[i-1]*powhash[j-i+1])%MOD+MOD)%MOD;
}

void solve(int BASE,int MOD){
    compute(BASE,MOD);
    
    int key=getTotalHash(BASE,MOD);
    for(int i=1;i+m-1<=n;++i){
        if(getHash(i,i+m-1,MOD)==key){
            cout<<i<<' ';
        }
    }
    cout<<'\n';
}

signed main(){
    cin>>s>>t;
    
    n=s.size();
    m=t.size();
    s='#'+s;
    t='#'+t;
    
    solve(41,1e9+9);
}
