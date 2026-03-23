#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000, MAXM = 1000;
int n, m, a[MAXN + 5], b[MAXM + 5];

int dp[MAXN + 5][MAXM + 5];
void solve(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    vector<int> res;
    int i = n, j = m;
    while(dp[i][j] > 0 && i > 0 && j > 0){
        while(dp[i][j] == dp[i - 1][j]){
            --i;
        }
        while(dp[i][j] == dp[i][j - 1]){
            --j;
        }

        res.push_back(a[i]);
        --i, --j;
    }

    reverse(begin(res), end(res));

    cout << dp[n][m] << '\n';
    for(int e: res){
        cout << e << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }

    solve();
    return 0;
}
