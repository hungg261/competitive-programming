#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;cin>>s;
    int ans=0;
    for(char k:s)ans+=k-'0';

    cout<<ans%9;
    return 0;
}