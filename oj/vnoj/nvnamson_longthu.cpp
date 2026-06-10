#include<bits/stdc++.h>
#define hash sussy
#define int long long
using namespace std;

const int MAXN=50000;
int n,k;
string s;

const int BASE=31,MOD=1e9+9;
int hash[MAXN+5],powhash[MAXN+5]={1};

int getHash(int i,int j){
    return ((hash[j]-hash[i-1]*powhash[j-i+1])%MOD+MOD)%MOD;
}

void compute(){
    for(int i=1;i<=n;++i){
        hash[i]=(hash[i-1]*BASE+(s[i]-'a'+1))%MOD;
        powhash[i]=(powhash[i-1]*BASE)%MOD;
    }
}

bool check(int mid){
    unordered_map<int,int>mark;
    for(int i=mid;i<=n;++i){
        int curHash=getHash(i-mid+1,i);
        ++mark[curHash];
        if(mark[curHash]>=k){
            return true;
        }
    }
    return false;
}

void solve(){
    int l=1,r=n,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LONGTHU.INP","r",stdin);
    freopen("LONGTHU.OUT","w",stdout);
    cin>>n>>k>>s;
    
    s='#'+s;
    compute();
    solve();
    return 0;
}
