/******************************************************************************
Link: https://marisaoj.com/problem/423
Code: 423
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-20-11.01.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, INF = 1e18;
const int MOD = 1e9 + 7;
int n, a[MAXN + 5];

namespace Brute{ void solve(); }

inline int sum(int l, int r, const vector<int> &P){
    if(l > r) return 0;
    return ((P[r] - P[l - 1]) % MOD + MOD) % MOD;
}

int mn[MAXN + 5], mx[MAXN + 5];
int solve(int L, int R){
    if(L > R) return 0;
    else if(L == R) return a[L] * a[L] % MOD;

    int mid = (L + R) >> 1;

    vector<int> mnR = {INF}, mxR = {-INF},
                Pmn = {0}, Pmx = {0}, P = {0};
    for(int i = mid + 1; i <= R; ++i){
        mnR.push_back(min(mnR.back(), a[i]));
        mxR.push_back(max(mxR.back(), a[i]));

        Pmn.push_back((Pmn.back() + mnR.back()) % MOD);
        Pmx.push_back((Pmx.back() + mxR.back()) % MOD);
        P.push_back((P.back() + mnR.back() * mxR.back() % MOD) % MOD);
    }
    int sz = R - mid;

    int p1 = 1, p2 = 1;
    int curmn = INF, curmx = -INF;
    int contrib = 0;
    for(int i = mid; i >= L; --i){
        curmn = min(curmn, a[i]);
        curmx = max(curmx, a[i]);

        while(p1 <= sz && mnR[p1] > curmn) ++p1;
        while(p2 <= sz && mxR[p2] < curmx) ++p2;

        contrib += (min(p1, p2) - 1) * curmn % MOD * curmx % MOD;
        contrib += curmx * sum(p1, p2 - 1, Pmn) % MOD;
        contrib += curmn * sum(p2, p1 - 1, Pmx) % MOD;
        contrib += sum(max(p1, p2), sz, P) % MOD;
        contrib %= MOD;
    }

    return (solve(L, mid) + contrib + solve(mid + 1, R)) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    cout << solve(1, n) << "\n";

    return 0;
}

namespace Brute{

void solve(){
    int res = 0;
    for(int i = 1; i <= n; ++i){
        int mn = LLONG_MAX, mx = LLONG_MIN;
        for(int j = i; j <= n; ++j){
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);

            res += mn * mx % MOD;
            res %= MOD;
        }
    }

    cout << res << "\n";
}

}
