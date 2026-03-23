/******************************************************************************
Link: https://marisaoj.com/problem/228
Code: 228
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-12.28.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
int powmod(int a, int b, int m = MOD){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = powmod(powmod(2, m) - 1, n) + powmod(powmod(2, n) - 1, m) - powmod(2, m * n);
    ans = (ans % MOD + MOD) % MOD;

    cout << ans << '\n';

	return 0;
}
