#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int diff[MAXN+5],n,Q;

void query(int l,int r,int x){
    diff[l]+=x;
    diff[r+1]-=x;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>Q;
    while(Q--){
        int type,l,r,x;
        cin>>type>>l>>r>>x;

        query(l,r,x*(type==1?1:-1));
    }

    int prefix=0;
    for(int i=1;i<=n;++i){
        prefix+=diff[i];
        cout<<prefix<<' ';
    }
    cout<<'\n';
    return 0;
}