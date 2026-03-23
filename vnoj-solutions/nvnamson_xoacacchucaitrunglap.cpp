#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
string s;
void solve(){
    int dem[26]={};
    bool visited[26]={};
    
    for(char c:s)++dem[c-'a'];
    
    vector<char>res;
    for(char c:s){
        --dem[c-'a'];
        if(visited[c-'a'])continue;
        
        while(!res.empty()&&res.back()>c&&dem[res.back()-'a']>0){
            visited[res.back()-'a']=false;
            res.pop_back();
        }
        
        res.push_back(c);
        visited[c-'a']=true;
    }
    
    for(char c:res)cout<<c;
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    
    solve();
    return 0;
}
