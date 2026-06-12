/******************************************************************************
Link: https://oj.vnoi.info/problem/parigame
Code: parigame
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-12-16.35.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int n;
int arr[MAXN + 5][MAXN + 5];
int pre[MAXN + 5][MAXN + 5];

inline int query(int x1, int y1, int x2, int y2){
    return pre[x2][y2] ^ pre[x1 - 1][y2] ^ pre[x2][y1 - 1] ^ pre[x1 - 1][y1 - 1];
}

inline int ngang(int i, int j){ return query(i, 1, i, j); }
inline int doc(int i, int j){ return query(1, j, i, j); }

int dp[MAXN + 5][MAXN + 5];
void compute(){
    for(int i = 0; i <= n; ++i) pre[i][0] = pre[0][i] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ arr[i][j];
        }
    }

    // grundy style
    for(int i = 0; i <= n; ++i) dp[i][0] = dp[0][i] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            set<int> S;
            if(ngang(i, j) == 0) S.insert(dp[i - 1][j]);
            if(doc(i, j) == 0) S.insert(dp[i][j - 1]);

            int mex = 0;
            while(S.count(mex)) ++mex;

            dp[i][j] = mex;
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> arr[i][j];
            arr[i][j] &= 1;
        }
    }

    compute();

    cout << (dp[n][n] ? "YES" : "NO") << "\n";
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
