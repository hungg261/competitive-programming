#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6;
int n,delta,a[MAX+1];

void solve(){
    deque<int>mindq,maxdq;
    int ans=0,i=0;
    for(int j=0;j<n;++j){
        while(!mindq.empty()&&a[mindq.back()]>=a[j])mindq.pop_back();
        while(!maxdq.empty()&&a[maxdq.back()]<=a[j])maxdq.pop_back();

        mindq.push_back(j);
        maxdq.push_back(j);
        
        while(a[maxdq.front()]-a[mindq.front()]>delta){
            ++i;
            if(maxdq.front()<i)maxdq.pop_front();
            if(mindq.front()<i)mindq.pop_front();
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>delta;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
