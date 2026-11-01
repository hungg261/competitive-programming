/******************************************************************************
Link: https://codeforces.com/problemset/gymProblem/105715/C
Code: Gym_105715C
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-01-21.45.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

struct Line {
    int a, b;

    int eval(int x) const {
        return a * x + b;
    }
};

struct Solution{
    int n, k;
    vector<int> arr;
    vector<int> pre;

    void input(){
        cin >> n >> k;
        arr.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
        }
        sort(begin(arr) + 1, end(arr));

        pre.resize(n + 1);
        pre[0] = 0;
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i - 1] + arr[i];
        }
    }

    inline int sum(int l, int r) const {
        return pre[r] - pre[l - 1];
    }

    inline int cost(int i, int j) const {
        return (j - i + 1) * arr[j] - sum(i, j);
    }

    void solve(){
        input();
//        Brute();
        Solve();
    }

private:
    bool bad(const Line &l1, const Line &l2, const Line &l3) const {
        return (__int128)(l2.b - l1.b) * (l2.a - l3.a) >= (__int128)(l3.b - l2.b) * (l1.a - l2.a);
    }

    void addLine(deque<Line> &dq, Line nl) const {
        while(dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), nl)){
            dq.pop_back();
        }
        dq.push_back(nl);
    }

    int query(deque<Line> &dq, int x) const {
        while(dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x)){
            dq.pop_front();
        }
        return dq.front().eval(x);
    }

    void Brute(){
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i){
            dp[i][1] = cost(1, i);
            for(int j = 2; j <= k; ++j){
                for(int p = j - 1; p < i; ++p){
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost(p + 1, i));
                }
            }
        }
        cout << dp[n][k] << "\n";
    }

    void Solve(){
        vector<int> dp_prev(n + 1, INF), dp_cur(n + 1, INF);
        for(int i = 1; i <= n; ++i){
            dp_prev[i] = cost(1, i);
        }

        for(int j = 2; j <= k; ++j){
            fill(dp_cur.begin(), dp_cur.end(), INF);
            deque<Line> dq;

            for(int i = j; i <= n; ++i){
                int p = i - 1;
                if(dp_prev[p] < INF / 2){
                    Line ln{-p, dp_prev[p] + pre[p]};
                    addLine(dq, ln);
                }

                if(!dq.empty()){
                    int best = query(dq, arr[i]);
                    dp_cur[i] = i * arr[i] - pre[i] + best;
                }
            }
            dp_prev = dp_cur;
        }
        cout << dp_prev[n] << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        Solution().solve();
    }

    return 0;
}
