#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2000;
int n, arr[MAXN + 5];

int dp[MAXN + 5][MAXN + 5];
void solve(){
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = 0;
        for(int j = 1; j <= i; ++j){
            if(dp[i - 1][j - 1] + arr[i] >= 0)
                dp[i][j] = max(dp[i - 1][j - 1] + arr[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

//    for(int i = 0; i <= n; ++i){
//        for(int j = 0; j <= n; ++j){
//            cerr << dp[i][j] << ' ';
//        }
//        cerr << '\n';
//    }

    for(int j = n; j >= 0; --j){
        if(dp[n][j] >= 0){
            cout << j << '\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
