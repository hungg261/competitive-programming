/******************************************************************************
Link: https://codeforces.com/problemset/problem/1771/C
Code: 1771C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-13-10.47.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MAXVAL = 1e9, MAXSIEVE = sqrt(MAXVAL) + 1;
bool not_prime[MAXSIEVE + 5];
int primes[MAXSIEVE + 5], pcnt = 0;

void sieve(){
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i * i <= MAXSIEVE; ++i){
        if(!not_prime[i]) for(int j = i * i; j <= MAXSIEVE; j += i){
            not_prime[j] = true;
        }
    }

    for(int i = 2; i <= MAXSIEVE; ++i){
        if(!not_prime[i]) primes[pcnt++] = i;
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    unordered_set<int> uprime;

    for(int i = 1; i <= n; ++i){
        int cur = arr[i];

        for(int pi = 0; pi < pcnt; ++pi){
            int p = primes[pi];
            if(p * p > cur) break;

            if(cur % p == 0){
                if(uprime.count(p)){
                    cout << "YES\n";
                    return;
                }
                uprime.insert(p);
            }

            while(cur % p == 0) cur /= p;
        }

        if(cur > 1){
            if(uprime.count(cur)){
                cout << "YES\n";
                return;
            }
            uprime.insert(cur);
        }
    }

    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    sieve();

    while(t--){
        solve();
    }

    return 0;
}
