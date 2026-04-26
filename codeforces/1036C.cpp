/******************************************************************************
Link: https://codeforces.com/contest/1036/problem/C
Code: 1036C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-26-23.06.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int num[20];
int dp[20][2][20];

int Try(int idx, int smaller, int cnt){
    if(idx < 0) return cnt <= 3;

    int& memo = dp[idx][smaller][cnt];
    if(memo != -1) return memo;

    int lim = smaller ? 9 : num[idx];
    memo = 0;

    for(int d = 0; d <= lim; ++d){
        memo += Try(idx - 1, smaller || (d < lim), cnt + (d != 0));
    }
    return memo;
}

int f(int n){
    int len = 0;
    while(n > 0){
        num[len++] = n % 10;
        n /= 10;
    }

    memset(dp, -1, sizeof dp);
    return Try(len - 1, 0, 0);
}

void solve(){
    int L, R;
    cin >> L >> R;

    cout << f(R) - f(L - 1) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
