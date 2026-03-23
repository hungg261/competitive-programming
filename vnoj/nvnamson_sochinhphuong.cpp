#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
int maxprime[MAXN + 5];
int factor[MAXN + 5];

void sieve(int n){
    for(int i = 2; i * i <= n; ++i){    
        if(maxprime[i] == 0){
            for(int j = i * i; j <= n; j += i){
                maxprime[j] = i;
            }
        }
    }
}

void pfactor(int n){
    while(n > 1){
        int p = maxprime[n];
        if(p == 0) p = n;
        
        while(n % p == 0){
            ++factor[p];
            n /= p;
        }
    }
}

const int MOD = 1e9 + 7;
int powmod(int a, int b, int mod = MOD){
    int res = 1 % mod;
    a %= mod;
    
    while(b > 0){
        if(b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    
    sieve(n);
    for(int i = 1; i <= n; ++i){
        pfactor(i);
    }
    
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        ans = 1LL * ans * powmod(i, factor[i] & (~1)) % MOD;
    }
    
    cout << ans << '\n';
    return 0;
}
