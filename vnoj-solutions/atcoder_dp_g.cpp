#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5,MAXM=1e5;
vector<vector<int>>children(MAXN+1);
int n,m;

int dp[MAXN+1];
int dfs(int node){
    if(dp[node]>0){
        return dp[node];
    }
    
    for(int child:children[node]){
        dp[node]=max(dp[node],dfs(child)+1);
    }
    return dp[node];
}

void solve(){
    for(int i=1;i<=n;++i){
        dfs(i);
    }
    cout<<*max_element(dp+1,dp+n+1)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        
        children[x].push_back(y);
    }
    
    solve();
    return 0;
}
