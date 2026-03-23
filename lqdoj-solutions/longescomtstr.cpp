#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("longescomtstr.INP","r",stdin);freopen("longescomtstr.OUT","w",stdout);
    string A,B;cin>>A>>B;
    int a=A.size(),b=B.size();

    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i1=a,i2=b,c=0;
    string ans="";
    while(i1>0&&i2>0){
        if(A[i1-1]==B[i2-1]){
            --i1;
            --i2;
            ++c;
            ans+=A[i1];
        }
        else if(dp[i1-1][i2]>=dp[i1][i2-1]) --i1;
        else --i2;
    }
    for(int i=c-1;i>=0;--i)cout<<ans[i];

    return 0;
}