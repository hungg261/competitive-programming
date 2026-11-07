/******************************************************************************
Link: https://codeforces.com/contest/2284/problem/C1
Code: 2284C1
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-06-22.45.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXVAL = 200000;
vector<int> primes;

void sieve(){
    vector<bool> isPrime(MAXVAL + 5, true);

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= MAXVAL; ++i){
        if(isPrime[i]){
            for(int j = i * i; j <= MAXVAL; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i <= MAXVAL; ++i){
        if(isPrime[i]) primes.push_back(i);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i){
        b[i] = *lower_bound(primes.begin(), primes.end(), a[i]);
    }

    for(int i = 0; i < n; ++i) cout << b[i] << " ";
    cout << "\n";

//    {
//        long long sa = 0, sx = 0;
//        for(int i = 0; i < n; ++i){
//            sa += a[i];
//            sx += b[i] - a[i];
//            if(b[i] - a[i] > 0 && __gcd(a[i], b[i] - a[i]) != 1) abort();
//        }
//        if(sx > sa) abort();
//        for(int i = 0; i < n; ++i){
//            for(int j = i + 1; j < n; ++j){
//                int g = __gcd(b[i], b[j]);
//                if(g > 1 && g < min(b[i], b[j])) abort();
//            }
//        }
//    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
