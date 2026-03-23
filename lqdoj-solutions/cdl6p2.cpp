#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0,q;i<n;++i){
        cin>>q;
        if(i!=k)cout<<q<<' ';
    }

    return 0;
}