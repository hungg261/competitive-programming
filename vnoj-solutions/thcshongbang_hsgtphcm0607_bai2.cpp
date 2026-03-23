/******************************************************************************
Link: https://oj.vnoi.info/problem/thcshongbang_hsgtphcm0607_bai2#submit
Code: thcshongbang_hsgtphcm0607_bai2
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-22-13.04.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

namespace Rabin_Miller{

#define int long long
int mulmod(int a, int b, int m){
    return (__int128)a * b % m;
    // return a * b % m;
}

int powmod(int a, int b, int m){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }

    return res;
}

bool check(int a, int n, int s, int d){
    int x = powmod(a, s, n);
    if(x == 1 || x == n - 1) return true;

    while(d--){
        x = mulmod(x, x, n);
        if(x == n - 1) return true;
    }

    return false;
}

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5 || n == 7) return true;
    if(n % 2 == 0) return false;
    if(n % 3 == 0) return false;
    if(n % 5 == 0) return false;
    if(n % 7 == 0) return false;

    int s = n - 1, d = 0;
    while(s % 2 == 0){
        s /= 2;
        ++d;
    }

    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int a: bases){
        if(a >= n) break;

        if(!check(a, n, s, d)){
            return false;
        }
    }

    return true;
}

}

namespace Pollard_Rho{

#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int f(int x, int c, int mod){
    return ((__int128)x * x + c) % mod;
}

int rho(int n){
    for(int t: {2, 3, 5, 7, 11, 13, 17, 19})
        if(n % t == 0) return t;
    if(Rabin_Miller::isPrime(n)) return n;

    while(true){
        int x = Rand(2, n - 2);
        int y = x;
        int c = Rand(1, n - 1);
        int d = 1;

        while(d == 1){
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);

            d = __gcd(llabs(x - y), n);
        }

        if(d != n) return d;
    }

    return -1;
}

void fact(int n, vector<int>& divisors){
    if(n == 1) return;
    if(Rabin_Miller::isPrime(n)){
        divisors.push_back(n);
    }
    else{
        int d = rho(n);
        fact(d, divisors);
        fact(n / d, divisors);
    }
}

}

int get_term(int p, int cnt){
    int term = 1;
    int cur = 1;
    for(int i = 0; i < cnt; ++i){
        cur *= p;
        term += cur;
    }

    return term;
}

bool is_sothua(int n){
    vector<int> ds;
    Pollard_Rho::fact(n, ds);

    sort(begin(ds), end(ds));

    int p = ds[0], cnt = 1;
    int dsum = 1;
    for(int i = 1; i < (int)ds.size(); ++i){
        if(ds[i] != p){
            dsum = dsum * get_term(p, cnt);
            p = ds[i], cnt = 1;
        }
        else ++cnt;
    }
    dsum = dsum * get_term(p, cnt);

    return dsum > n * 2;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ANUM.INP","r",stdin);
    freopen("ANUM.OUT","w",stdout);

    int N;
    cin >> N;

    while(!is_sothua(N)) ++N;
    cout << N << '\n';

    return 0;
}
