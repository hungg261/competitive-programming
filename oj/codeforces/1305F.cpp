/******************************************************************************
Link: https://codeforces.com/contest/1305/problem/F
Code: 1305F
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-31-17.31.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = LLONG_MAX / 2;
const int MAXN = 2e5;
int n, a[MAXN + 5];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int calc(int d){
    if(d < 2) return INF;

    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] < d) res += d - a[i];
        else res += min(a[i] % d, d - a[i] % d);
    }
    return res;
}

int solve(int x){
    if(x < 2) return INF;

    int res = INF;
    if(x % 2 == 0) res = min(res, calc(2));
    while(x % 2 == 0){
        x /= 2;
    }

    for(int i = 3; i * i <= x; i += 2){
        if(x % i == 0) res = min(res, calc(i));
        while(x % i == 0){
            x /= i;
        }
    }

    if(x > 1) res = min(res, calc(x));
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    shuffle(a + 1, a + n + 1, rng);

    int res = INF;
    for(int i = 1; i <= n; ++i){
        if(1.0 * clock() / CLOCKS_PER_SEC > 2.2) break;
        res = min({res, solve(a[i]), solve(a[i] - 1), solve(a[i] + 1)});
    }

    cout << res << "\n";

    return 0;
}
