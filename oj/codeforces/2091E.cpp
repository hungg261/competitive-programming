/******************************************************************************
Link: https://codeforces.com/problemset/problem/2091/E
Code: 2091E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-23.29.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool not_prime[MAX + 5];
vector<int> primes;

void sieve(){
    for(int i = 2; i * i <= MAX; ++i){
        if(!not_prime[i]) for(int j = i * i; j <= MAX; j += i)
            not_prime[j] = true;
    }

    for(int i = 2; i <= MAX; ++i){
        if(!not_prime[i]) primes.push_back(i);
    }
}

void solve(){
    int n;
    cin >> n;

    long long res = 0;
    for(int p: primes){
        if(p > n) break;
        res += n / p;
    }

    cout << res << '\n';
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
