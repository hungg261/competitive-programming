#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=300,MAXVAL=600,MAXTOTAL=MAXN*MAXVAL+3;
int n,a[MAXN+5],total=0;
bitset<MAXTOTAL> dp[MAXN+5];

void solve(){
    dp[0][0]=true;
    for(int i=1;i<=n;++i){
        for(int j=i;j>=1;--j){
            dp[j]|=dp[j-1]<<a[i];
        }
        dp[1][a[i]]=true;
    }
    
    int cnt=n/2;
    int diff=1e9,left=-1,right=-1;
    for(int k=total;k>=1;--k){
        if(dp[cnt][k]){
            int res1=k,res2=total-k;
            if(abs(res2-res1)<diff){
                diff=abs(res2-res1);
                left=res1,right=res2;
            }
        }
    }
    
    if(left>right)swap(left,right);
    cout<<left<<' '<<right<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        total+=a[i];
    }
    
    solve();
    return 0;
}
