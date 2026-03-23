#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    cin>>n;
    
    priority_queue<int>pq;
    int ans=0;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        
        pq.push(cur);
        int top=pq.top();
        if(cur<top){
            pq.push(cur);
            
            ans+=top-cur;
            pq.pop();
        }
    }
    
    cout<<ans<<'\n';
    return 0;
}
