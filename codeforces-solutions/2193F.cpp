/******************************************************************************
Link: https://codeforces.com/contest/2193/problem/F
Code: 2193F
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-09-20.11.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second

const int INF = 1e18;

struct State{
    int x, y1, y2;
};

int f(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> coords(n + 3);
    cin >> coords[n + 1].x >> coords[n + 1].y;
    cin >> coords[n + 2].x >> coords[n + 2].y;
    for(int i = 1; i <= n; ++i) cin >> coords[i].x;
    for(int i = 1; i <= n; ++i) cin >> coords[i].y;
    sort(begin(coords) + 1, end(coords));

    vector<State> layers;
    int mn = INF, mx = -INF;
    for(int i = 1; i <= n + 2; ++i){
        if(i == 1 || coords[i].x == coords[i - 1].x){
            mn = min(mn, coords[i].y);
            mx = max(mx, coords[i].y);
        }
        else{
            layers.push_back({coords[i - 1].x, mn, mx});
            mn = mx = coords[i].y;
        }
    }
    layers.push_back({coords.back().x, mn, mx});

    int l = layers.size();
    vector<vector<int>> dp(l, vector<int>(2));
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < l; ++i){
        const State& cur = layers[i];
        const State& prv = layers[i - 1];

        dp[i][0] = min(dp[i - 1][1] + f(cur.x, cur.y1, prv.x, prv.y1),
                       dp[i - 1][0] + f(cur.x, cur.y1, prv.x, prv.y2));
        dp[i][1] = min(dp[i - 1][1] + f(cur.x, cur.y2, prv.x, prv.y1),
                       dp[i - 1][0] + f(cur.x, cur.y2, prv.x, prv.y2));

        dp[i][0] += cur.y2 - cur.y1;
        dp[i][1] += cur.y2 - cur.y1;
    }

    cout << min(dp[l - 1][0], dp[l - 1][1]) << '\n';
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
