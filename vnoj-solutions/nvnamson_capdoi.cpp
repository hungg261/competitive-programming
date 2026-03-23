#include<bits/stdc++.h>
using namespace std;

const int MAX=5e5;
int a[MAX+1],n;

void solve(){
    stack<int>sta;
    long long ans=0;
    for(int i=1;i<=n;++i){
        while(!sta.empty()&&sta.top()<a[i]){
            sta.pop();
        }
        if(!sta.empty())++ans;
        sta.push(a[i]);
    }
    
    while(!sta.empty())sta.pop();
    for(int i=n;i>=1;--i){
        while(!sta.empty()&&sta.top()<a[i]){
            sta.pop();
        }
        if(!sta.empty()&&a[i]!=sta.top())++ans;
        sta.push(a[i]);
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
