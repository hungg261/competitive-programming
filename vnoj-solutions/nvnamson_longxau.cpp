#include<bits/stdc++.h>
#define int long long
using namespace std;

int calc(string s){
    int res=0;
    for(int i=1;i<s.size();++i){
        if(s[i-1]!=s[i]){
            if(s[i-1]=='a'){
                ++res;
            }
            else --res;
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LONGXAU.INP","r",stdin);
    freopen("LONGXAU.OUT","w",stdout);
    string s;
    int n;
    cin>>n>>s;
    
    if(s[0]=='?')s[0]='a';
    for(int i=1;i<n;++i){
        if(s[i]=='?'){
            s[i]='b';
        }
    }
    
    cout<<calc(s)<<'\n';
    return 0;
}
