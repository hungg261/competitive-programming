/******************************************************************************
Link: https://oj.uz/problem/view/APIO14_sequence
Code: APIO14_sequence
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-04-16.37.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXK = 200;
int n, k, arr[MAXN + 5];
int P[MAXN + 5];

inline int sum(int l, int r){ return P[r] - P[l - 1]; }

inline int cost(int l, int r){
    int S = sum(l, r);
    int idx = lower_bound(P + l, P + r + 1, P[l - 1] + S / 2) - P;

    int best = 0;
    for(int i = idx; i >= idx - 1; --i){
        if(l <= i && i < r)
            best = max(best, sum(l, i) * sum(i + 1, r));
    }

    return best;
}

long long dp[2][MAXN + 5];
int trace[MAXK + 5][MAXN + 5];

struct Line{
    long long m, c;
    int id;

    long long eval(long long x) const { return m * x + c; }
};
vector<Line> hull;

template<typename _T> inline int sz(const _T& vec){ return (int)vec.size(); }

bool is_bad(const Line& l1, const Line& l2, const Line& l3){
    return 1.0 * (l1.c - l2.c) * (l3.m - l1.m) >= 1.0 * (l2.m - l1.m) * (l1.c - l3.c);
}

void solve(){
    memset(dp, 0, sizeof dp);
    int ptr = 0;
    for(int c = 1; c <= k; ++c){
        memset(dp[c & 1], -1, sizeof dp[c & 1]);
        hull.clear(); ptr = 0;
        for(int j = 1; j <= n; ++j){
            long long x = P[j] - P[n];
            if(dp[c - 1 & 1][j - 1] != -1){
                Line cur = {P[j - 1], dp[c - 1 & 1][j - 1], j - 1};
                while(sz(hull) >= 2 && is_bad(hull[sz(hull) - 2], hull[sz(hull) - 1], cur))
                    hull.pop_back();
                hull.push_back(cur);

                while(ptr + 1 < sz(hull) && hull[ptr + 1].eval(x) > hull[ptr].eval(x))
                    ++ptr;
                if(ptr >= sz(hull)) ptr = max(0, sz(hull) - 1);

                dp[c & 1][j] = hull[ptr].eval(x) + 1LL * P[j] * P[n] - 1LL * P[j] * P[j];
                trace[c][j] = hull[ptr].id;
            }


//            for(int i = 1; i <= j; ++i){
//                if(dp[c - 1 & 1][i - 1] < 0) continue;
//
//
//                long long val = 1LL * P[i - 1] * (P[j] - P[n]) + dp[c - 1 & 1][i - 1] + 1LL * P[j] * P[n] - 1LL * P[j] * P[j];
////                long long val = dp[c - 1 & 1][i - 1] + 1LL * sum(i, j) * sum(j + 1, n);
//                if(val > dp[c & 1][j]){
//                    dp[c & 1][j] = val;
//                    trace[c][j] = i - 1;
//                }
//            }
        }
    }

//    for(int c = 0; c <= k; ++c){
//        for(int i = 0; i <= n; ++i){
//            cerr << (dp[c][i] < 0 ? -1 : dp[c][i]) << "\t";
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
        P[i] = P[i - 1] + arr[i];
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
        P[i] = P[i - 1] + arr[i];
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
