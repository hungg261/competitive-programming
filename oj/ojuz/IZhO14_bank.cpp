#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20, MAXM = 20, MAXMASK = 1 << MAXM;
int N, M;
int a[MAXN], b[MAXM], dp[MAXN][MAXMASK];

namespace Brute{

int sum[MAXMASK];
void compute(){
    sum[0] = 0;
    for(int mask = 1; mask < MAXMASK; ++mask){
        int i = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ (1 << i)] + b[i];
    }
}

int Try(int idx, int mask){
    if(idx < 0) return 1;

    int& memo = dp[idx][mask];
    if(memo != -1) return memo;

    memo = 0;
    for(int sub = mask; sub; sub = (sub - 1) & mask){
        if(sum[sub] == a[idx]){
            if(Try(idx - 1, mask & ~sub)){
                memo = 1;
                break;
            }
        }
    }

    return memo;
}

void solve(){
    compute();
    sort(a, a + N);
    sort(b, b + N);

    memset(dp, -1, sizeof dp);
    cout << (Try(N - 1, (1 << M) - 1) ? "YES\n" : "NO\n");
}

}

namespace Solve{

pair<int, int> dp[MAXMASK];
void solve(){
    for(int mask = 0; mask < (1 << M); ++mask)
        dp[mask] = {-1, INT_MIN};
    dp[0] = {0, 0};
    for(int mask = 0; mask < (1 << M); ++mask){
        int idx, rem; tie(idx, rem) = dp[mask];

        if(idx == -1) continue;
        else if(idx == N){
            cout << "YES\n";
            return;
        }

        rem *= -1;
        for(int i = 0; i < M; ++i){
            if(~mask >> i & 1){
                int nextMask = mask | (1 << i);

                int next_dp = idx, next_rem = rem + b[i];
                if(rem + b[i] == a[idx]){
                    next_dp = idx + 1;
                    next_rem = 0;
                }

                dp[nextMask] = max(dp[nextMask], {next_dp, -next_rem});
            }
        }
    }

    cout << "NO\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < M; ++i) cin >> b[i];

    Solve::solve();

    return 0;
}
