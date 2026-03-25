/******************************************************************************
Link: https://codeforces.com/contest/2000/problem/F
Code: 2000F
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-24-10.59.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Rect{
    int n, m;

    void input(){
        cin >> n >> m;
        if(n > m) swap(n, m);
    }

    pair<int, int> use(){
        pair<int, int> res = {1, n};

        --m;
        if(n > m) swap(n, m);

        return res;
    }

    bool valid(){
        return n > 0 || m > 0;
    }

    bool operator < (const Rect& other) const{
        return n > other.n;
    }

    void output() const{
        cerr << n << " " << m << "\n";
    }
};

const int INF = 1e9;
void solve(){
    int n, k;
    cin >> n >> k;

    vector<Rect> rects(n + 1);
    for(int i = 1; i <= n; ++i){
        rects[i].input();
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];

        Rect& cur = rects[i];
        int gain = 0, area = 0;

        while(cur.valid()){
            int C, S;
            tie(C, S) = cur.use();

            gain += C;
            area += S;

            for(int j = k; j >= gain; --j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - gain] + area);
        }
    }

    cout << (dp[n][k] == INF ? -1 : dp[n][k]) << "\n";
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
