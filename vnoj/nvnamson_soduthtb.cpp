#include<bits/stdc++.h>
#define int long long
using namespace std;

int mulmod(int a, int b, int mod){
    int res = 0;
    a %= mod;
    
    while(b > 0){
        if(b & 1) res = (res + a) % mod;;
        a = (a << 1) % mod;
        b >>= 1;
    }
    
    return res;
}

int powmod(int a, int b, int mod){
    int res = 1 % mod;
    a %= mod;
    
    while(b > 0){
        if(b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    
    return res;
}

int digitcnt;
int solve(int x, int n, int m){
    if(n == 0){
        return 0;
    }
    
    if(n & 1){
        return (mulmod(solve(x, n - 1, m), powmod(10, digitcnt, m), m) + x) % m;
    }
    
    int half = solve(x, n / 2, m);
    return (mulmod(half, powmod(10, (n / 2) * digitcnt, m), m) + half) % m;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, n, m;
    cin >> x >> n >> m;
    
    int temp = x;
    while(temp > 0){
        ++digitcnt;
        temp /= 10;
    }
    
    cout << solve(x % m, n, m) << '\n';
    return 0;
}
