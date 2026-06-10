/******************************************************************************
Link: https://codeforces.com/contest/2123/problem/F
Code: 2123F
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-12.26.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int not_prime[MAX + 5];

void sieve(){
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i * i <= MAX; ++i){
        for(int j = i * i; j <= MAX; j += i){
            not_prime[j] = true;
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1, -1);
    p[1] = 1;

    for(int i = n; i >= 2; --i){
        if(not_prime[i]) continue;

        vector<int> cand;
        for(int j = i; j <= n; j += i){
            if(p[j] == -1) cand.push_back(j);
        }

        if((int)cand.size() == 1){
            p[i] = i;
            continue;
        }

        rotate(begin(cand), begin(cand) + 1, end(cand));
        for(int j = i, idx = 0; j <= n; j += i){
            if(p[j] == -1) p[j] = cand[idx++];
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << p[i] << ' ';
    cout << '\n';
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
