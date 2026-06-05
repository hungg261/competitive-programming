/******************************************************************************
Link: https://oj.uz/problem/view/APIO14_sequence
Code: APIO14_sequence
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-16.37.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXK = 200;
int n, k, arr[MAXN + 5];
int pre[MAXN + 5];

inline int sum(int l, int r){ return pre[r] - pre[l - 1]; }

inline int cost(int l, int r){
    int S = sum(l, r);
    int idx = lower_bound(pre + l, pre + r + 1, pre[l - 1] + S / 2) - pre;

    int best = 0;
    for(int i = idx; i >= idx - 1; --i){
        if(l <= i && i < r)
            best = max(best, sum(l, i) * sum(i + 1, r));
    }

    return best;
}

long long dp[2][MAXN + 5];
int trace[MAXK + 5][MAXN + 5];

void solve(){
    memset(dp, 0, sizeof dp);
    for(int c = 1; c <= k; ++c){
        memset(dp[c & 1], -1, sizeof dp[c & 1]);
        for(int j = 1; j <= n; ++j){
            for(int i = 1; i <= j; ++i){
                if(dp[c - 1 & 1][i - 1] < 0) continue;

                long long val = dp[c - 1 & 1][i - 1] + 1LL * sum(i, j) * sum(j + 1, n);
                if(val > dp[c & 1][j]){
                    dp[c & 1][j] = val;
                    trace[c][j] = i - 1;
                }
            }
        }
    }

//    for(int c = 0; c <= k; ++c){
//        for(int i = 0; i <= n; ++i){
//            cerr << (dp[c][i].first < 0 ? -1 : dp[c][i].first) << "\t";
//        }
//        cerr << endl;
//    }

//    int pos = max_element(dp[k & 1], dp[k & 1] + n + 1) - dp[k & 1];
//    cout << dp[k & 1][pos] << "\n";
//
//    for(int c = k; c > 0; --c){
//        cout << pos << " ";
//        pos = trace[c][pos];
//    }
}

void trau(){
    memset(dp, 0, sizeof dp);
    for(int c = 1; c <= k; ++c){
        memset(dp[c & 1], -1, sizeof dp[c & 1]);
        for(int j = 1; j <= n; ++j){
            for(int i = 1; i <= j; ++i){
                if(dp[c - 1 & 1][i - 1] < 0) continue;

                long long val = dp[c - 1 & 1][i - 1] + 1LL * sum(i, j) * sum(j + 1, n);
                if(val > dp[c & 1][j]){
                    dp[c & 1][j] = val;
                    trace[c][j] = i - 1;
                }
            }
        }
    }

//    for(int c = 0; c <= k; ++c){
//        for(int i = 0; i <= n; ++i){
//            cerr << (dp[c][i].first < 0 ? -1 : dp[c][i].first) << "\t";
//        }
//        cerr << endl;
//    }

    int pos = max_element(dp[k & 1], dp[k & 1] + n + 1) - dp[k & 1];
    cout << dp[k & 1][pos] << "\n";

    for(int c = k; c > 0; --c){
        cout << pos << " ";
        pos = trace[c][pos];
    }
}

void gen(){
    cerr << endl;

    n = rand() % 1000 + 2;
    k = min(200, rand() % (n - 1) + 1);

    for(int i = 1; i <= n; ++i){
        arr[i] = rand() % 10000;
        pre[i] = pre[i - 1] + arr[i];
    }

    cerr << "TEST:\n";
    cerr << n << " " << k << "\n";
    for(int i = 1; i <= n; ++i) cerr << arr[i] << " "; cerr << endl;

    cerr << "=====\n";
    solve();
    cerr << "\n=====\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

//    trau();
    solve();

//    srand(time(0));
//    while(true){
//        gen();
//        system("pause");
//    }

    return 0;
}
