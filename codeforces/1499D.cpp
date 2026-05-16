/******************************************************************************
Link: https://codeforces.com/contest/1499/problem/D
Code: 1499D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-16-10.17.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e7;
int spf[MAX + 5], pcnt[MAX + 5];

void compute(){
    for(int i = 2; i * i <= MAX; ++i){
        if(!spf[i]) for(int j = i * i; j <= MAX; j += i)
            if(!spf[j]) spf[j] = i;
    }

    for(int i = 2; i <= MAX; ++i){
        if(spf[i] == 0) spf[i] = i;

        int prv = i / spf[i];
        if(spf[prv] != spf[i]) pcnt[i] = pcnt[prv] + 1;
        else pcnt[i] = pcnt[prv];
    }
}

void solve(){
    int c, d, x;
    cin >> c >> d >> x;

    auto cnt = [&](int D){
        if((D + d) % c != 0) return 0;

        int AB = (D + d) / c;
        return 1 << pcnt[AB];
    };

    long long res = 0;
    for(int g = 1; g * g <= x; ++g){
        if(x % g == 0){
            res += cnt(x / g);
            if(g * g != x) res += cnt(g);
        }
    }

    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    compute();
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
