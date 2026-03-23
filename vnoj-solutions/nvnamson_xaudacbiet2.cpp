#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5, MOD=1e9+7;
int prefix[123][MAX+1],n;
string s,app;

string decode(int idx){
    int sz=app.size();
    string decoded_string="";
    for(int i=1;i<sz;++i){
        decoded_string+=to_string(prefix[app[i]][idx]-prefix[app[i-1]][idx]);
        decoded_string+='#';
    }
    return decoded_string;
}

void solve(){
    unordered_map<string,int>Q;
    Q[decode(0)]=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        string code=decode(i);
        ans=(ans+Q[code])%MOD;
        
        ++Q[code];
    }
    cout<<ans<<'\n';
}

signed main(){
    cin>>n>>s;
    n=s.size();
    for(int i=0;i<n;++i){
        for(int j='a';j<='z';++j){
            prefix[j][i+1]=prefix[j][i];
        }
        for(int j='A';j<='Z';++j){
            prefix[j][i+1]=prefix[j][i];
        }
        if(prefix[s[i]][i+1]==0){
            app+=s[i];
        }
        ++prefix[s[i]][i+1];
    }
    
    solve();
    return 0;
}
