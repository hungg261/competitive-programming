/******************************************************************************
Link: https://codeforces.com/contest/895/problem/C
Code: 895C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-21-08.49.37
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> basis;
void add(int x){
    for(int b : basis) x = min(x, x ^ b);
    for(int i = 0; i < (int)basis.size(); ++i){
        if(x > basis[i]){
            basis.insert(basis.begin() + i, x);
            return;
        }
    }
    if(x > 0) basis.push_back(x);
}

bool is_prime(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return n > 1;
}

int prime[71];
void compute(){
    for(int i = 1; i <= 70; ++i){
        prime[i] = prime[i - 1] + is_prime(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    compute();

    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        int mask = 0;
        for(int j = 2; j * j <= cur; ++j){
            while(cur % j == 0){
                cur /= j;
                mask ^= 1 << prime[j] - 1;
            }
        }
        if(cur > 1) mask ^= 1 << prime[cur] - 1;
        add(mask);
    }

    int sz = basis.size();
    int res = 1;
    const int MOD = 1e9 + 7;
    for(int b = 1; b <= n - sz; ++b){
        res = 2LL * res % MOD;
    }

    cout << (res - 1 + MOD) % MOD << "\n";

    return 0;
}
