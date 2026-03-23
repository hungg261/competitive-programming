#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+1,MOD=1e9+7;
int n,dp[MAX]={1};
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=6;++j){
            if(i>=j)dp[i]=(dp[i]%MOD+dp[i-j]%MOD)%MOD;
        }
    }
    cout<<dp[n];
}