#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("cntnum.INP","r",stdin);freopen("cntnum.OUT","w",stdout);
    int n,a=0,b=0;cin>>n;
    while(n--){
        int q;cin>>q;
        if(q<0)++a;
        else if(q>0)++b;
    }
    cout<<a<<' '<<b;

    return 0;
}