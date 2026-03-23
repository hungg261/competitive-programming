#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;cin>>s;
    int n=s.size();

    int l=0,h=0,ans=0;
    while(h<n){
        if(s[l]==s[h]){
            ++h;
            ans=max(ans,h-l);
        }
        else ++l;
    }
    cout<<ans;
    return 0;
}