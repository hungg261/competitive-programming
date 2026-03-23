#include<bits/stdc++.h>
#define int long long
using namespace std;

int res=1000;
void solve(string n){
    for(int mask=0;mask<(1<<(int)n.size());++mask){
        int chosen=0;
        for(int i=0;i<n.size();++i){
            if(mask&(1<<i)){
                chosen=chosen*10+n[i]-'0';
            }
        }
        
        // cerr<<chosen<<'\n';
        if(chosen%3==0){
            res=min(res,(int)n.size()-__builtin_popcount(mask));
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    cin>>n;
    
    solve(n);
    return 0;
}
