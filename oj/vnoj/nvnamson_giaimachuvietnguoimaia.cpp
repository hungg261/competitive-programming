#include<bits/stdc++.h>
using namespace std;

int g,s;
string G,S;

int mark[52],cur_mark[52];
int getIdx(char k){
    if(k<'a')return k-'A';
    return k-'a'+26;
}

bool check(){
    for(int i=0;i<52;++i){
        if(mark[i]!=cur_mark[i])return false;
    }
    return true;
}

void solve(){
    int ans=0;
    if(check())++ans;
    for(int i=g;i<s;++i){
        --cur_mark[getIdx(S[i-g])];
        ++cur_mark[getIdx(S[i])];
        
        if(check())++ans;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>g>>s>>G>>S;
    
    for(int i=0;i<g;++i){
        ++mark[getIdx(G[i])];
        ++cur_mark[getIdx(S[i])];
    }
    
    solve();
    return 0;
}
