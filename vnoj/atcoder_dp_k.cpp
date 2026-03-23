#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000,MAXK=1e5;
int a[MAXN+1],n,k;
bool dp[MAXK+1];

void solve(){
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            if(i>=a[j]&&!dp[i-a[j]]){
                dp[i]=true;
                break;
            }
        }
    }
    
    cout<<(dp[k]?"First\n":"Second\n");
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    solve();
    return 0;
}
