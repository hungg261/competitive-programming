#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

const int MAXN=50000,BASE=29,MOD=1e6+3;
string s;
int n,k;
int hash[MAXN+5],powhash[MAXN+5]={1};

void compute(){
    for(int i=1;i<=n;++i){
        powhash[i]=(powhash[i-1]*BASE)%MOD;
        hash[i]=(hash[i-1]*BASE+s[i]-'a'+1)%MOD;
    }
}

int freq[MOD];
int getHash(int i,int j){
    return ((hash[j]-hash[i-1]*powhash[j-i+1])%MOD+MOD)%MOD;
}

bool check(int mid){
    memset(freq,0,sizeof freq);
    for(int i=1;i+mid-1<=n;++i){
        // cerr<<getHash(i,i+mid-1)<<' ';
        ++freq[getHash(i,i+mid-1)];
    }
    
    return *max_element(freq,freq+MOD)>=k;
}

int tknp(){
    int l=1,h=n,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>s;
    s='#'+s;
    compute();
    
    cout<<tknp()<<'\n';
    return 0;
}
