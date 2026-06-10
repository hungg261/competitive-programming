/******************************************************************************
Link: https://codeforces.com/contest/1423/problem/K
Code: 1423K
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-22.52.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
bool not_prime[MAX + 5];
int pre[MAX + 5];

void sieve(){
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i * i <= MAX; ++i){
        if(!not_prime[i]) for(int j = i * i; j <= MAX; j += i){
            not_prime[j] = true;
        }
    }

    for(int i = 0; i <= MAX; ++i){
        pre[i] = pre[i - 1] + (!not_prime[i]);
    }
}

void solve(){
    int n;
    cin >> n;

    int sq = sqrt(n) + 1e-9;
    int res = pre[n] - pre[sq] + 1;

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    sieve();
    while(t--){
        solve();
    }

    return 0;
}
