#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n, int k, const vector<int>& primes){
    int ans = 0;
    for(int mask = 1; mask < (1 << k); ++mask){
        int prod = 1, cnt = 0;
        for(int i = 0; i < k; ++i){
            if(mask & (1 << i)){
                if(prod > n / primes[i]) goto skipped;

                prod *= primes[i];
                ++cnt;
            }
        }

        if(cnt & 1) ans += n / prod;
        else ans -= n / prod;
        skipped: NULL;
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> primes(k);
    for(int& prime: primes) cin >> prime;

    cout << solve(n, k, primes) << '\n';

    return 0;
}
