#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int i=s.size()-1;

    for(;i>=0&&s[i]!='0';--i);
    cout<<i+1;
    return 0;
}