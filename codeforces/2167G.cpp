#include<bits/stdc++.h>
#define int long long
using namespace std;

void compress(vector<int>& arr){
    vector<int> temp = arr;
    sort(begin(temp) + 1, end(temp));
    temp.erase(unique(begin(temp), end(temp)), end(temp));

    for(int i = 1; i < (int)arr.size(); ++i){
        arr[i] = lower_bound(begin(temp), end(temp), arr[i]) - begin(temp);
    }
}

const int INF = 1e18;
void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), c(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> c[i];

    compress(a);
    vector<vector<int>> minDp(2, vector<int>(n + 1, INF));
    for(int j = 1; j <= n; ++j){
        int cur = c[1] * (j != a[1]);
        minDp[1][j] = min(minDp[1][j - 1], cur);
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int cur = minDp[i - 1 & 1][j] + c[i] * (j != a[i]);
            minDp[i & 1][j] = min(minDp[i & 1][j - 1], cur);
//            for(int k = 1; k <= j; ++k){
//                dp[i][j] = min(dp[i][j], dp[i - 1][k]) + c[i] * (j != a[i]);
//            }
        }
    }

//    for(int i = 1; i <= n; ++i) cerr << a[i] << ' ' << c[i] << '\n'; cerr << '\n';
//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= n; ++j){
//            cerr << dp[i][j] << ' ';
//        }
//        cerr << '\n';
//    }

//    int ans = *min_element(begin(dp[n & 1]) + 1, end(dp[n & 1]));
    int ans = minDp[n & 1][n];
    cout << ans << '\n';
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
