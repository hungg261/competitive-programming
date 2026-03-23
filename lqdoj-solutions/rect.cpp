#include<bits/stdc++.h>
#define int long long
#define left sussy
#define right baka
using namespace std;

const int MAX=5e5;
int m,n,a[MAX+1];
int left[MAX+1],right[MAX+1];

void compute(){
    stack<int>sta;
    for(int i=1;i<=n;++i){
        while(!sta.empty()&&a[sta.top()]>=a[i]){
            sta.pop();
        }

        if(!sta.empty())left[i]=sta.top()+1;
        else left[i]=1;
        sta.push(i);
    }

    while(!sta.empty())sta.pop();
    for(int i=n;i>=1;--i){
        while(!sta.empty()&&a[sta.top()]>=a[i]){
            sta.pop();
        }

        if(!sta.empty())right[i]=sta.top()-1;
        else right[i]=n;
        sta.push(i);
    }
}

int solve(){
    compute();

    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,a[i]*(right[i]-left[i]+1));
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    int ans=solve();
    for(int i=1;i<=n;++i){
        a[i]=m-a[i];
    }
    ans=max(ans,solve());
    cout<<ans<<'\n';
    return 0;
}