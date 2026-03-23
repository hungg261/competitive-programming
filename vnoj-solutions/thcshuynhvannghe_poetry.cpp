#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int MAXN = 1e7;
int a[MAXN + 5], b[MAXN + 5];

int mod(int u, int v){
    return (u % v + v) % v;
}

void generate(int arr[], int len, int x, int y, int m){
    arr[1] = 1;
    arr[2] = 2;
    
    x %= m;
    y %= m;
    
    for(int i = 3; i <= len; ++i){
        arr[i] = mod(arr[i - 1] * x % m + arr[i - 2] * y % m + i * i % m, m);
    }
}

ull g(ull x){
    return x * (x + 1) * (x + 2) * 12297829382473034411ull;
}

int bignum_mod(string num, int mod){
    int res = 0;
    for(int digit: num){
        res = (res * 10 + digit - '0') % mod;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    
    string big_x, big_y;
    int x, y, m;
    cin >> big_x >> big_y >> m;
    
    x = bignum_mod(big_x, m);
    y = bignum_mod(big_y, m);
    
    generate(a, n, x, y, m);
    
    ull ans = 0;
    for(int i = 1; i <= n; ++i){
        ull value = g(a[i] * a[i] * a[i]);
        
        ans ^= value;
    }
    
    cout << ans << '\n';
    
    return 0;
}
