#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;

    int layer=max(x,y),
        previous=(layer-1)*(layer-1);
    int ans=0;
    if(layer%2==1){
        if(x>=y){
            ans=previous+y;
        }
        else{
            ans=previous+y+layer-x;
        }
    }
    else{
        if(x>=y){
            ans=layer*layer-y+1;
        }
        else{
            ans=layer*layer-(y+layer-x)+1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}