/******************************************************************************
Link: https://eolymp.com/problems/465
Code: 465
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-25-13.38.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 16;
int n, m, k;

int a[MAXN + 5];
int dp[1 << MAXN][MAXN];

namespace Solve{

void solve(){
    sort(a, a + n);

    for(int i = 0; i < n; ++i)
        dp[(1 << n) - 1][i] = 1;

    for(int mask = (1 << n) - 1; mask >= 0; --mask){
        for(int i = 0; i < n; ++i){
            if(~mask >> i & 1) continue;

            for(int j = 0; j < n; ++j){
                if(i == j || (mask >> j & 1)) continue;

                if(__gcd(a[i], a[j]) >= k){
                    int nxt_mask = mask | (1 << j);
                    dp[mask][i] += dp[nxt_mask][j];
                }
            }
        }
    }

    int total = 0;
    for(int i = 0; i < n; ++i)
        total += dp[1 << i][i];

    if(total < m){
        cout << -1 << "\n";
        return;
    }


    int mask = 0, last = -1;
    vector<int> res;
    for(int pos = 0; pos < n; ++pos){
        for(int i = 0; i < n; ++i){
            if(mask >> i & 1) continue;
            if(last != -1 && __gcd(last, a[i]) < k) continue;

            int cnt = dp[mask | (1 << i)][i];
            if(m > cnt) m -= cnt;
            else{
                res.push_back(a[i]);
                last = a[i];
                mask |= 1 << i;
                break;
            }
        }
    }

    for(int x: res) cout << x << " ";
    cout << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    Solve::solve();

    return 0;
}
