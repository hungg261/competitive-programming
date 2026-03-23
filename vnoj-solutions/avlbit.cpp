#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5,MAXK=16;
int n,q,a[MAXN+1],table[MAXK+1][MAXN+1][4];

void compute(){
    unordered_map<int,int>mark;
    for(int i=1;i<=n;++i){
        table[0][i][0]=table[0][i][1]=a[i];
        table[0][i][2]=abs(a[i]-a[i-1]);
        
        table[0][i][3]=mark[a[i]];
        mark[a[i]]=i;
    }
    
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i<=n;++i){
            table[j][i][0]=min(table[j-1][i][0],table[j-1][i+(1<<(j-1))][0]);
            table[j][i][1]=max(table[j-1][i][1],table[j-1][i+(1<<(j-1))][1]);            
            table[j][i][2]=__gcd(table[j-1][i][2],table[j-1][i+(1<<(j-1))][2]);        
            table[j][i][3]=max(table[j-1][i][3],table[j-1][i+(1<<(j-1))][3]);
        }
    }
}

int minquery(int l,int r){
    int bit=__lg(r-l+1),
        length=1<<bit;
        
    return min(table[bit][l][0],table[bit][r-length+1][0]);
}

int maxquery(int l,int r){
    int bit=__lg(r-l+1),
        length=1<<bit;
        
    return max(table[bit][l][1],table[bit][r-length+1][1]);
}

int gcdquery(int l,int r){
    int bit=__lg(r-l+1),
        length=1<<bit;
        
    return __gcd(table[bit][l][2],table[bit][r-length+1][2]);
}

int markquery(int l,int r){
    int bit=__lg(r-l+1),
        length=1<<bit;
        
    return max(table[bit][l][3],table[bit][r-length+1][3]);
}

void solve(){
    int l,r;
    cin>>l>>r;
    
    int maxpos=markquery(l,r);
    if(maxpos>=l){
        cout<<"NO\n";
        return;
    }
    
    int low=minquery(l,r),
        high=maxquery(l,r),
        step=gcdquery(l+1,r);
    
    int dist=high-low;
    if(step!=0&&dist%step==0&&dist/step+1==r-l+1){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    compute();
    while(q--)solve();
    return 0;
}
