#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int diff[MAXN+5];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    
    while(q--){
        int x,y;
        cin>>x>>y;
        
        ++diff[x];
        --diff[y+1];
    }
    
    int prefix=0;
    for(int i=1;i<=n;++i){
        prefix+=diff[i];
        cout<<prefix%2<<' ';
    }
    return 0;
}
