#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("str01.INP","r",stdin);freopen("str01.OUT","w",stdout);
    string a,b;
    getline(cin,a);
    getline(cin,b);

    int ans=a.size()-b.size();
    cout<<abs(ans);
    return 0;
}