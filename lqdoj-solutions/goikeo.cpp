// Bai tuong tu:
// https://codeforces.com/contest/713/problem/C
// https://lqdoj.edu.vn/problem/goikeo

#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[5005][5005],n,a[5005],b[5005];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);
    dp[1][1]=abs(a[1]-b[1]);
    for(int i=2; i<=n; ++i)
        dp[i][1]=dp[i-1][1]+abs(a[i]-b[1]);

    for(int j=2; j<=n; ++j) {
        dp[1][j]=min(abs(a[1]-b[j]),dp[1][j-1]);
        for(int i=2; i<=n; ++i) {
            dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[i]-b[j]));
        }
    }

    cout<<dp[n][n]<<'\n';
    return 0;
}