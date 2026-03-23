/******************************************************************************
Link: https://codeforces.com/contest/432/problem/D
Code: 432D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-09-22.45.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int BASES[] = {27, 29, 31, 33, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const int MODS[] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 998244353, 1000000123, 1000000181};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int BASE = BASES[rng() % (sizeof(BASES) / sizeof(BASES[0]))];
int MOD  = MODS [rng() % (sizeof(MODS)  / sizeof(MODS[0]))];

const int MAXN = 1e5;
int hashes[MAXN + 5], powhash[MAXN + 5];
string s;
int n;

void compute(){
    powhash[0] = 1;
    for(int i = 1; i <= n; ++i){
        hashes[i] = (hashes[i - 1] * BASE + (s[i] - 'A' + 1)) % MOD;
        powhash[i] = powhash[i - 1] * BASE % MOD;
    }
}

int getHash(int l, int r){
    return ((hashes[r] - hashes[l - 1] * powhash[r - l + 1]) % MOD + MOD) % MOD;
}

int Z[MAXN + 5];
void computeZ(){
    for(int i = 2; i <= n; ++i){
        int l = 1, r = n - i + 1;

        Z[i] = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getHash(1, mid) == getHash(i, i + mid - 1)){
                Z[i] = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
}

int res[MAXN + 5];
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(Z[i] > 0){
            res[1]++;
            res[Z[i] + 1]--;
        }

        if(getHash(1, i) == getHash(n - i + 1, n))
            ++cnt;
    }

    int prefix = 0;

    cout << cnt << '\n';
    for(int i = 1; i <= n; ++i){
        prefix += res[i];

        if(getHash(1, i) == getHash(n - i + 1, n)){
            cout << i << ' ' << prefix + 1 << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;

    compute();
    computeZ();

    solve();

    return 0;
}
