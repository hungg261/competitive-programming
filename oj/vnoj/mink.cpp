#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=17000,MAXK=15;
int n,k,a[MAXN+1];

int table[MAXK][MAXN+1];
void compute(){
    for(int i=1;i<=n;++i){
        table[0][i]=a[i];
    }
    
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i<=n;++i){
            table[j][i]=min(table[j-1][i],table[j-1][i+(1<<(j-1))]);
        }
    }
}

int query(int l,int r){
    int ans=a[l];
    int len=r-l+1;
    
    for(int bit=0;len>0;++bit){
        if(len&1){
            ans=min(ans,table[bit][l]);
            l+=1<<bit;
        }
        len>>=1;
    }
    return ans;
    
    // int bit=__lg(r-l+1),
    //     length=1<<bit;
    // return min(table[bit][l],table[bit][r-length+1]);
}

void solve(){
    compute();
    for(int i=k;i<=n;++i){
        cout<<query(i-k+1,i)<<' ';
    }
    cout<<'\n';
}

void input(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        input();
    }
    return 0;
}
