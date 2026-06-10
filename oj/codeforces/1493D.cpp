/******************************************************************************
Link: https://codeforces.com/contest/1493/problem/D
Code: 1493D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-31-17.13.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
int powmod(int a, int b, int m = MOD){
    int res = 1 % m;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int MAXN = 2e5, MAXVAL = 2e5;
int n, q;
map<int, int> a[MAXN + 5];
multiset<int> cnt[MAXVAL + 5];

int spf[MAXVAL + 5];
void sieve(){
    for(int i = 2; i <= MAXVAL; ++i){
        if(!spf[i]){
            for(int j = i * 2; j <= MAXVAL; j += i) if(!spf[j]) spf[j] = i;
        }
    }
}

int res = 1;
void add(int i, int cur){
    while(cur > 1){
        int p = spf[cur];
        if(p == 0) p = cur;

        int c = 0;
        while(cur % p == 0){
            cur /= p;
            ++c;
        }

        int& mu = a[i][p];

        auto it = cnt[p].find(mu);
        if(it != cnt[p].end()){
            if((int)cnt[p].size() == n){
                res = res * powmod(powmod(p, *cnt[p].begin()), MOD - 2) % MOD;
            }

            cnt[p].erase(it);
        }

        cnt[p].insert(mu += c);

        if((int)cnt[p].size() == n){
            res = res * powmod(p, *cnt[p].begin()) % MOD;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    sieve();

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        add(i, cur);
    }

    while(q--){
        int i, x;
        cin >> i >> x;

        add(i, x);
        cout << res << "\n";
    }

    return 0;
}
