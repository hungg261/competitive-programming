#include<bits/stdc++.h>
using namespace std;

const int MAXSQRT = 1e6;
bool not_prime[MAXSQRT + 5];
vector<int> primes;

void sieve(){
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i * i <= MAXSQRT; ++i){
        for(int j = i * i; j <= MAXSQRT; j += i){
            not_prime[j] = true;
        }
    }

    primes.push_back(2);
    for(int i = 3; i <= MAXSQRT; i += 2){
        if(!not_prime[i]) primes.push_back(i);
    }
}

bool is_prime(long long n){
    if(n <= 1) return false;

    for(int prime: primes){
        if((long long)prime * prime > n) break;

        if(n % prime == 0) return false;
    }

    return true;
}

void solve(){
    long long n;
    cin >> n;

    if(n + 1 == 2){
        cout << "2\n";
        return;
    }

    for(long long j = (n + 1) | 1; ; j += 2){
        if(is_prime(j)){
            cout << j << '\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    sieve();
    while(t--){
        solve();
    }
    return 0;
}
