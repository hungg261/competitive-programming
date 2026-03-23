#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
int n;
int dp[MAXN * 2 + 5][MAXN * 2 + 5];
string a[MAXN + 5];

void trace(){
    string res = "";

    int y = n;
    for(int dcheo = n * 2 - 1; dcheo > 1; --dcheo){
        res += a[min(dcheo - y + 1, n)][y];

        y = dp[dcheo - 1][y - 1] < dp[dcheo - 1][y] ? y - 1: y;
    }

    res += a[1][1];

    reverse(begin(res), end(res));
    cout << res << '\n';
}

void solve(){
    memset(dp, 0x3f, sizeof dp);

    dp[1][1] = 1;
    for(int i = 2; i <= n * 2 - 1; ++i){
        int x = min(i, n), y = max(1, i - n + 1);
        while(x >= 1 && y <= n){
            dp[i][y] = min(dp[i - 1][y - 1], dp[i - 1][y]) * 29 + a[x][y] - 'A' + 1;

            --x;
            ++y;
        }

        int l = max(1, i - n + 1), r = min(i, n);
        int min_value = *min_element(dp[i] + l, dp[i] + r + 1);
        for(int idx = l; idx <= r; ++idx){
            if(dp[i][idx] == min_value) dp[i][idx] = 1;
            else dp[i][idx] = dp[0][0];
        }
    }

    trace();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] = '#' + a[i];
    }

    solve();
    return 0;
}
