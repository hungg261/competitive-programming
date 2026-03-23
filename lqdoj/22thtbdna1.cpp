#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("demkt.inp","r",stdin);freopen("demkt.out","w",stdout);
    string s;cin>>s;
    cout<<count(begin(s),end(s),'9');
    return 0;
}