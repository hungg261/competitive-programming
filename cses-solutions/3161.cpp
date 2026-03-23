#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int x[MAXN + 5], mark[MAXN + 5], n;
int cnt[MAXN + 5];

int powmod(int a, int b, int mod = MOD){
    int res = 1 % MOD;
    a %= mod;

    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; j += i){
            cnt[i] += mark[j];
        }
        cnt[i] = powmod(2, cnt[i]) - 1;
    }

    for(int i = n; i >= 1; --i){
        for(int j = i * 2; j <= n; j += i){
            cnt[i] -= cnt[j];
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << (cnt[i] % MOD + MOD) % MOD << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        ++mark[x[i]];
    }

    solve();

    return 0;
}
