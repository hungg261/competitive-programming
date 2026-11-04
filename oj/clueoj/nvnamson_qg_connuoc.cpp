/******************************************************************************
Link: https://oj.clue.edu.vn/problem/nvnamson_qg_connuoc
Code: nvnamson_qg_connuoc
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-03-20.36.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int N, H, Q;

namespace Brute{


int solve(int A, int B){
    vector<long long> dp(H, 0), nxt_dp(H, 0);
    dp[A] = 1;
    for(int step = 1; step <= N; ++step){
        fill(begin(nxt_dp), end(nxt_dp), 0);
        for(int lvl = 1; lvl <= H - 1; ++lvl){
            if(dp[lvl] == 0) continue;

            nxt_dp[lvl] = (nxt_dp[lvl] + dp[lvl]) % MOD;
            if(lvl + 1 <= H - 1) nxt_dp[lvl + 1] = (nxt_dp[lvl + 1] + dp[lvl]) % MOD;
            if(lvl - 1 >= 1) nxt_dp[lvl - 1] = (nxt_dp[lvl - 1] + dp[lvl]) % MOD;
        }

        swap(dp, nxt_dp);
    }

    return dp[B];
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> H >> Q;
    while(Q--){
        int A, B; cin >> A >> B;
        cout << Brute::solve(A, B) << "\n";
    }

    return 0;
}
