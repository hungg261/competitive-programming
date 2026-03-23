#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5;
int a[MAX+1],n;

int dp[MAX+1],len=0;
void solve(){
    dp[len++]=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>dp[len-1]){
            dp[len++]=a[i];
        }
        else *lower_bound(dp,dp+len,a[i])=a[i];
    }
    
    int cnt=len;
    for(int i=0;i<n;++i)a[i]=-a[i];
    len=0;
    dp[len++]=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>=dp[len-1]){
            dp[len++]=a[i];
        }
        else dp[lower_bound(dp,dp+len,a[i],less_equal<int>())-dp]=a[i];
    }
    
    cout<<len<<'\n'<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>a[n]){
        ++n;
    }
    solve();

    return 0;
}
