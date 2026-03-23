#include<bits/stdc++.h>
using namespace std;

#define int long long

int powmod(int a, int b, int m){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i){
        sum1 += arr[i]; sum1 %= MOD;
        sum2 += arr[i] * arr[i]; sum2 %= MOD;
    }

    int ans = (sum1 * sum1 - sum2) % MOD * powmod(2, MOD - 2, MOD) % MOD * powmod(n * (n - 1) / 2, MOD - 2, MOD) % MOD;
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
