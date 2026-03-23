#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e6,MAXVAL_sub5=4e5;
int n,a[MAXN+5];

int dp[MAXN+5];
void sub1234(){
    for(int i=1;i<=n;++i){
        dp[i]=1;
        for(int j=1;j<i;++j){
            if(a[i]%a[j]==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp+1,dp+n+1)<<'\n';
}

int mark[MAXVAL_sub5+5];
void sub5(){
    for(int i=1;i<=n;++i){
        ++mark[a[i]];
    }
    
    n=unique(a+1,a+n+1)-a-1;
    for(int i=1;i<=n;++i){
        dp[a[i]]=max(dp[a[i]],mark[a[i]]);
        for(int j=a[i]*2;j<=MAXVAL_sub5;j+=a[i]){
            if(mark[j]>0){
                dp[j]=max(dp[j],dp[a[i]]+mark[j]);
            }
        }
    }
    
    // for(int i=1;i<=12;++i){
    //     cout<<dp[i]<<' ';
    // }
    cout<<*max_element(dp,dp+MAXVAL_sub5+1)<<'\n';
}

void solve(){
    sort(a+1,a+n+1);
    if(n<=10000){
        sub1234();
    }
    else sub5();
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
