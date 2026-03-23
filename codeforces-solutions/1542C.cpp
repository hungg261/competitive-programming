#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int lcm(int a, int b){
    a /= __gcd(a, b);
    if(a > INF / b) return INF;

    return a * b;
}

const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    int L = 1, nxtL = 1;
    int ans = 0;
    for(int num = 2; num <= 100; ++num){
        L = lcm(L, num - 1);
        nxtL = lcm(L, num);

        ans += num * (n / L) % MOD;
        ans -= num * (n / nxtL) % MOD;
        ans %= MOD;
    }

    cout << (ans + MOD) % MOD << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
