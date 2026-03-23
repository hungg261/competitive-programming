#include<bits/stdc++.h>
using namespace std;

string n;
int k;

void solve(){
    stack<int>sta;
    int m=n.size();
    for(int i=0;i<m;++i){
        while(!sta.empty()&&n[sta.top()]<n[i]){
            n[sta.top()]='#';
            sta.pop();
            --k;
            
            if(k==0){
                goto passed;
            }
        }
        sta.push(i);
    }
    passed:0;
    string res;
    for(int i=0;i<m;++i){
        if(n[i]!='#'){
            res+=n[i];
        }
    }
    cout<<res.substr(0,(int)res.size()-k)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    
    solve();
    return 0;
}
