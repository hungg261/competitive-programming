/******************************************************************************
Link: https://codeforces.com/contest/559/problem/C
Code: 559C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-11-17.34.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Point{
    int x, y, diag;

    Point(int _x = 0, int _y = 0): x(_x), y(_y){ diag = _diag(); }

    inline int _diag() const { return x + y; }

    bool operator < (const Point& other) const { return diag < other.diag || (diag == other.diag && x < other.x); }
    bool operator == (const Point& other) const { return x == other.x && y == other.y; }
};

const int MAX = 1e5, MAXDIAG = MAX * 2 + 5, MAXN = 2000;
const int MOD = 1e9 + 7;
int fact[MAXDIAG + 5], inv[MAXDIAG + 5];

int powmod(int a, int b, int m = MOD){
    a %= m;
    int res = 1;

    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAXDIAG; ++i){
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv[MAXDIAG] = powmod(fact[MAXDIAG], MOD - 2, MOD);
    for(int i = MAXDIAG - 1; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int k){
    if(n < 0 || k < 0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int h, w, n;
vector<int> diag[MAXDIAG + 5];
vector<Point> P;
vector<int> lost;

void solve(){
    for(int dg = 0; dg <= MAXDIAG; ++dg){
        for(int i: diag[dg]){
            const Point& U = P[i];
            for(int j = i + 1; j < (int)P.size(); ++j){
                const Point& V = P[j];

                int newH = V.y - U.y, newW = V.x - U.x;
                lost[j] = (lost[j] - C(newH + newW, newH) * lost[i] % MOD + MOD) % MOD;
            }
        }
    }

    cout << lost.back() << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;

        --x; --y;
        P.emplace_back(x, y);
    }

    compute();

    P.emplace_back(h - 1, w - 1);
    sort(begin(P), end(P));
    P.erase(unique(begin(P), end(P)), end(P));

    lost.resize(P.size());
    for(int i = 0; i < (int)P.size(); ++i){
        diag[P[i].diag].push_back(i);
        lost[i] = C(P[i].x + P[i].y, P[i].x);
    }

    solve();

    return 0;
}
