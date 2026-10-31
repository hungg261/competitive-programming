/******************************************************************************
Link: https://codeforces.com/gym/101873/problem/B
Code: Gym_101873B
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-30-20.09.21
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
int n, m, c;

int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> c;

    int res = 0;
    for(int i = 1; i <= m; ++i){
        res = (res + powmod(powmod(c, n * n), __gcd(i, m))) % MOD;
    }

    res = res * powmod(m, MOD - 2) % MOD;
    cout << res << "\n";

    return 0;
}
