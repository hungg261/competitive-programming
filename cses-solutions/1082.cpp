#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long find_upper_constant(long long n, long long expected, long long l, long long r){
    long long res = -1;
    while(l <= r){
        long long mid = (l + r) / 2, value = n / mid;
        if(value >= expected){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

long long sum(long long a, long long b, const int& mod){
    return ((a + b) % (mod * 2)) * ((b - a + 1) % (mod * 2)) % (mod * 2) / 2;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;

    long long low = 0, high = 0;
    int ans = 0;
    for(long long i = 1; i <= n; ){
        long long expected = n / i;
        low = high + 1, high = find_upper_constant(n, expected, i, n);

        ans = ans + sum(low, high, MOD) * expected % MOD;
        ans %= MOD;
        i = high + 1;

        if(ans < 0) break;
    }

    cout << ans << '\n';
    return 0;
}
