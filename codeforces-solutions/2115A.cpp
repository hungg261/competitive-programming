#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 5000;
int GCD[MAX + 5][MAX + 5];
void compute(){
    for(int i = 1; i <= MAX; ++i) GCD[i][0] = GCD[0][i] = i;
    for(int i = 1; i <= MAX; ++i){
        for(int j = 1; j <= i; ++j){
            GCD[i][j] = GCD[j][i] = GCD[i - j][j];
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int g = 0;
    for(int ele: arr) g = GCD[g][ele];

    int cnt = count(begin(arr), end(arr), g);
    if(cnt > 0){
        cout << n - cnt << '\n';
        return;
    }

    const int INF = 1e9;
    int maxval = *max_element(begin(arr), end(arr));

    vector<int> dp(maxval + 1, INF);
    for(int ele: arr) dp[ele] = 0;

    for(int x = maxval; x >= 1; --x){
        for(int i = 0; i < n; ++i){
            int& nxt = dp[GCD[x][arr[i]]];
            nxt = min(nxt, dp[x] + 1);
        }
    }

    cout << dp[g] + (n - 1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    compute();
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
