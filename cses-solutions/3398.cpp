#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int arr[MAXN + 5], p[MAXN + 5];
int n;

struct DSU{
    vector<int> parent, sz;

    DSU() = default;
    DSU(int n){ parent.resize(n); sz.resize(n); }

    void create_set(int v){ parent[v] = v; sz[v] = 1; }
    int find_set(int v){ return parent[v] == v ? v : parent[v] = find_set(parent[v]); }

    void union_sets(int u, int v){
        int a = find_set(u),
            b = find_set(v);

        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

int spf[MAXN + 5];
void compute(){
    for(int i = 2; i * i <= MAXN; ++i){
        for(int j = i * i; j <= MAXN; j += i){
            if(spf[j] == 0) spf[j] = i;
        }
    }
}

int factor[MAXN + 5];
void pfactor(int n){
    while(n > 1){
        int p = spf[n];
        if(p == 0) p = n;

        int cnt = 0;
        while(n % p == 0){
            n /= p;
            ++cnt;
        }
        factor[p] = max(factor[p], cnt);
    }
}

const int MOD = 1e9 + 7;
int powmod(int a, int b, int mod = MOD){
    int res = 1;
    a %= mod;

    while(b > 0){
        if(b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }

    return res;
}

void solve(){
    DSU dsu(n + 1);
    for(int i = 1; i <= n; ++i) dsu.create_set(i);
    for(int i = 1; i <= n; ++i) dsu.union_sets(i, p[i]);
    for(int i = 1; i <= n; ++i) pfactor(dsu.sz[dsu.find_set(i)]);

    int ans = 1;
    for(int f = 1; f <= MAXN; ++f){
        if(factor[f] > 0) ans = 1LL * ans * powmod(f, factor[f]) % MOD;
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];

    compute();
    solve();

    return 0;
}
