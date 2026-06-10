/******************************************************************************
Link: https://codeforces.com/contest/5/problem/C
Code: 5C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-08.27.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n;
string s;

int dp[MAXN + 5];
void solve(){
    s = "#" + s;
    dp[0] = 0;

    int res = 0, cnt = 1;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '(') dp[i] = 0;
        else{
            int j = i - dp[i - 1] - 1;

            if(j >= 0 && s[j] == '(')
                dp[i] = dp[j - 1] + dp[i - 1] + 2;
            else dp[i] = 0;
        }

        if(dp[i] > res){
            res = dp[i];
            cnt = 1;
        }
        else if(dp[i] == res)
            ++cnt;
    }

    cout << res << " " << (res == 0 ? 1 : cnt) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.size();

    solve();

    return 0;
}
