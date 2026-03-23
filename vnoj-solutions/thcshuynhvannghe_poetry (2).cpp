#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int MAXN = 1e7;
int a[MAXN + 5], n;
__int128 MOD = 1;

void print(__int128 x){
    if(x < 0){
        cout << ('-');
        x = -x;
    }
    
    if(x > 9) print(x / 10);
    cout << (char)(x % 10 + '0');
}

__int128 g(int ai, __int128 x){
    __int128 x1 = x + 1, x2 = x + 2;
    
    if(x % 3 == 0) return x / 3 % MOD * x1 % MOD * x2 % MOD;
    if(x1 % 3 == 0) return x1 / 3 % MOD * x % MOD * x2 % MOD;
    if(x2 % 3 == 0) return x2 / 3 % MOD * x1 % MOD * x % MOD;
    
    throw "sus";
}

int bignum_mod(string num, int mod){
    int res = 0;
    for(int digit: num){
        res = (res * 10 + digit - '0') % mod;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1; i <= 64; ++i) MOD *= 2;
    
    cin >> n;
    
    string big_x, big_y;
    int x, y, m;
    cin >> big_x >> big_y >> m;
    
    x = bignum_mod(big_x, m);
    y = bignum_mod(big_y, m);
    
    a[1] = 1; a[2] = 2;
    for(int i = 3; i <= n; ++i){
        a[i] = (a[i - 1] * x % m + a[i - 2] * y % m + i * i % m) % m;
    }
    
    ull ans = 0;
    for(int i = 1; i <= n; ++i){
        ans ^= g(a[i], a[i] * a[i] * a[i]);
    }
    
    print(ans);
    // cout << ans << '\n';
    
    return 0;
}
