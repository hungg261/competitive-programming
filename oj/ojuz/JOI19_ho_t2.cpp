/******************************************************************************
Link: https://oj.uz/problem/view/JOI19_ho_t2
Code: JOI19_ho_t2
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-13-18.03.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 1e5;
int N, M;

struct Picture{
    int S, V;

    bool operator < (const Picture& other) const {
        return (V < other.V) || (V == other.V && S < other.S);
    }

    bool operator > (const Picture& other) const {
        return (V > other.V) || (V == other.V && S > other.S);
    }

    friend istream& operator >> (istream& is, Picture& p){
        return is >> p.S >> p.V;
    }
} P[MAXN + 5];
int F[MAXM + 5];

namespace Brute{

void solve1(){
    int res = 0;
    sort(P + 1, P + N + 1);
    sort(F + 1, F + M + 1);
    for(int mask1 = 1; mask1 < (1 << N); ++mask1){
        int cnt = __builtin_popcount(mask1);
        if(res >= cnt) continue;

        vector<int> A;
        for(int i = 0; i < N; ++i){
            if(mask1 >> i & 1)
                A.push_back(P[i + 1].S);
        }

        for(int mask2 = 0; mask2 < (1 << M); ++mask2){
            if(__builtin_popcount(mask2) != cnt) continue;

            vector<int> B;
            for(int i = 0; i < M; ++i){
                if(mask2 >> i & 1)
                    B.push_back(F[i + 1]);
            }

            if([&](){
                for(int i = 0; i < cnt; ++i){
                    if(A[i] > B[i]) return false;
                }
                return true;
            }()) res = max(res, cnt);
        }
    }

    cout << res << "\n";
}


void solve2(){
    sort(P + 1, P + N + 1);
    sort(F + 1, F + M + 1);
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    dp[0][0] = 0;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(P[i].S <= F[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << dp[N][M] << "\n";
}

}

namespace Solve{

void solve(){
    sort(P + 1, P + N + 1, greater<Picture>());
    sort(F + 1, F + M + 1, greater<int>());

    int i = 1, j = 1;
    int res = 0;
    while(i <= N && j <= N){
        if(P[i].S <= F[j]){
            ++res;
            ++i; ++j;
        }
        else{
            ++i;
        }
    }

    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; ++i) cin >> P[i];
    for(int i = 1; i <= M; ++i) cin >> F[i];

    Solve::solve();

    return 0;
}
