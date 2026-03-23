/******************************************************************************
Link: https://atcoder.jp/contests/abc447/tasks/abc447_d
Code: abc447_d
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-28-19.02.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn = 1e6;
int dp[maxn + 7][4];
void input(){
    cin>>s;
}
void solve(){
    int n = s.size();
    s = " " + s;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 3;j++)dp[i][j] = dp[i - 1][j];
        if(s[i] == 'A'){
            dp[i][0] = dp[i - 1][0] + 1;
        }
        else{
            dp[i][0] = dp[i - 1][0];
        }
        if(s[i] == 'B'){
            if(dp[i - 1][0] != 0){
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0]--;
            }
        }
        if(s[i] == 'C'){
            if(dp[i - 1][1] != 0){
                dp[i][2] = dp[i - 1][2] + 1;
                dp[i][1]--;
            }
        }
    }
    cout<<dp[n][2];
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solve();
    return 0;
}
