/******************************************************************************
Link: https://vjudge.net/problem/CodeChef-SANSKAR
Code: CodeChef-SANSKAR
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-10-15.01.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long sum = 0;
    for(long long& x: a){
        cin >> x;
        sum += x;
    }

    if(sum % k != 0){
        cout << "no\n";
        return;
    }

    long long target = sum / k;

    vector<pair<int, long long>> dp(1 << n, {-1, LLONG_MIN});
    dp[0] = {0, 0};

    for(int mask = 0; mask < (1 << n); ++mask){
        int cnt; long long rem; tie(cnt, rem) = dp[mask];
        if(cnt == -1) continue;

        rem *= -1;
        for(int i = 0; i < n; ++i){
            if(~mask >> i & 1){
                int next_dp = cnt; long long next_rem = rem + a[i];
                if(rem + a[i] == target){
                    next_dp = cnt + 1;
                    next_rem = 0;
                }

                int nextMask = mask | (1 << i);
                dp[nextMask] = max(dp[nextMask], {next_dp, -next_rem});
            }
        }
    }

    if(dp.back().first >= k) cout << "yes\n";
    else cout << "no\n";
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
