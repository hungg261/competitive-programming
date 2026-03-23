#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e6;
int a[MAXN*2+5],n,prefix[MAXN*2+5];

void solve(){
    deque<int>dq;
    int ans=0;
    for(int i=1;i<n*2;++i){
        if(!dq.empty()&&i-dq.front()+1>n)dq.pop_front();
        while(!dq.empty()&&prefix[dq.back()]>prefix[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        if(i>=n){
            if(prefix[dq.front()]-prefix[i-n]>0)++ans;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    
    for(int i=1;i<=n*2;++i){
        prefix[i]=prefix[i-1]+a[i];
    }
    solve();
    return 0;
}
