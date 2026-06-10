/******************************************************************************
Link: https://codeforces.com/contest/2182/problem/D
Code: 2182D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-07-22.29.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

void trau(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    int S = 0;
    for(int i = 0; i <= n; ++i){
        cin >> a[i];
        S += a[i];
    }

    vector<int> perm(n + 1);
    iota(begin(perm) + 1, end(perm), 1);

    do{
        vector<int> temp = a;
        bool ok = true;
        for(int i = 1; i <= S; ++i){
            int idx = perm[(i - 1) % n + 1];
            if(temp[idx] > 0) --temp[idx];
            else --temp[0];

            if(temp[0] < 0){
                ok = false;
                break;
            }
        }


        if(ok){
            temp = a;
            for(int i = 1; i <= S / n * n; ++i){
                int idx = perm[(i - 1) % n + 1];
                if(temp[idx] > 0) --temp[idx];
                else --temp[0];

                if(temp[0] < 0){
                    ok = false;
                    break;
                }
            }

            cerr << "found:\n";
            for(int i = 0; i <= n; ++i) cerr << temp[i] << ' '; cerr << '\n';
            for(int i = 1; i <= n; ++i) cerr << perm[i] << ' '; cerr << '\n';
        }
    } while(next_permutation(begin(perm) + 1, end(perm)));

}

const int MAX = 1e6;
int fact[MAX + 5];

int powmod(int a, int b, int m){
    int res = 1;
    a %= m;

    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void compute(){
    fact[0] = 1;
    for(int i = 1; i <= MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
}

int C(int n, int k){
    if(n < k || k < 0 || n < 0) return 0;
    return fact[n] * powmod(fact[k] * fact[n - k], MOD - 2, MOD) % MOD;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);

    int S = 0;
    for(int i = 0; i <= n; ++i){
        cin >> a[i];
        S += a[i];
    }

    int tries = S / n;
    for(int i = 1; i <= n; ++i){
        if(a[i] >= tries) a[i] -= tries;
        else{
            if(a[0] >= tries - a[i]) a[0] -= tries - a[i];
            else{
                cout << 0 << '\n';
                return;
            }
            a[i] = 0;
        }

        if(a[i] > 1){
            cout << 0 << '\n';
            return;
        }
    }

    int sad = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i] == 0) ++sad;

    int yay = sad - a[0];

    int res = C(sad, yay) * fact[yay] % MOD * fact[n - yay] % MOD;
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    compute();
    while(t--){
        solve();
    }

    return 0;
}
