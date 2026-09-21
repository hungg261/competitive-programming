/******************************************************************************
Link: https://coding.fit.hcmus.edu.vn/problem/discs
Code: discs
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-21-18.27.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 16;
const double INF = 1e18;
int n;

inline int pow2(int x){ return x * x; }

struct Point{
    int x, y;

    double dist(const Point& other) const {
        return sqrt(pow2(x - other.x) + pow2(y - other.y));
    }

    void input(){
        cin >> x >> y;
    }
} P[MAXN];

namespace Solve{

double dp[1 << MAXN][MAXN];
void solve(){
    for(int i = 0; i < n; ++i){
        for(int mask = 0; mask < (1 << n); ++mask)
            dp[mask][i] = INF;

        dp[1 << i][i] = 0;
    }

    for(int mask = 0; mask < (1 << n); ++mask){
        for(int i = 0; i < n; ++i){
            if(mask >> i & 1) for(int j = 0; j < n; ++j){
                if(i != j && (mask >> j & 1)){
                    int prevMask = mask ^ (1 << j);
                    dp[mask][j] = min(dp[mask][j], dp[prevMask][i] + P[i].dist(P[j]));
                }
            }
        }
    }
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        P[i].input();
    }

    Solve::solve();

    return 0;
}
