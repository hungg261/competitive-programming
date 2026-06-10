#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("w04.INP","r",stdin);freopen("w04.OUT","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=i;j<2*i;++j)cout<<j<<" \n"[j==2*i-1];

    return 0;
}