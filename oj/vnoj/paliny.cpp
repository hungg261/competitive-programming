#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

const int MAXN=1e5;
const int BASE=883,MOD=1e9+9;
int n,hash[2][MAXN+5],powhash[2][MAXN+5];
string s,rev_s;

void compute(int type,const string&str){
    powhash[type][0]=1;
    for(int i=1;i<=n;++i){
        powhash[type][i]=(powhash[type][i-1]*BASE)%MOD;
    }
    
    for(int i=1;i<=n;++i){
        hash[type][i]=(hash[type][i-1]*BASE+(str[i]-'a'+1))%MOD;
    }
}

int getHash(int i,int j,int type){
    return ((hash[type][j]-hash[type][i-1]*powhash[type][j-i+1])%MOD+MOD)%MOD;
}

bool check(int mid){
    for(int i=1;i+mid-1<=n;++i){
        // cerr<<i<<' '<<i+mid/2-1<<" | "<<i+(mid-1)/2+1<<' '<<i+mid-1<<" | "<<getHash(i,i+mid/2-1,0)<<' '<<getHash(n-(i+mid-1)+1,n-(i+(mid-1)/2+1)+1,1)<<'\n';
        if(getHash(i,i+mid/2-1,0)==getHash(n-(i+mid-1)+1,n-(i+(mid-1)/2+1)+1,1)){
            return true;
        }
    }
    return false;
}

int tknp_le(){
    int l=1,h=(n+1)/2,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        // cerr<<mid*2-1<<' '<<check(mid*2-1)<<'\n';
        if(check(mid*2-1)){
            res=mid*2-1;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return res;
}

int tknp_chan(){
    int l=1,h=n/2,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid*2)){
            res=mid*2;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return res;
}

signed main(){
    cin>>n>>s;
    rev_s=s;
    reverse(begin(rev_s),end(rev_s));
    
    // cout<<s<<'\n'<<rev_s<<'\n';
    s='#'+s;
    rev_s='#'+rev_s;
    compute(0,s);
    compute(1,rev_s);
    
    // cout<<getHash(2,3,0)<<' '<<getHash(2,3,1)<<'\n';
    // cerr<<tknp_chan()<<"\n----------------\n"<<tknp_le()<<"\n----------------\n";
    cout<<max(tknp_chan(),tknp_le())<<'\n';
    // cerr<<check(4)<<' '<<getHash(4,5,0)<<' '<<getHash(1,2,1)<<'\n';
    return 0;
}
