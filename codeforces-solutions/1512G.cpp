/******************************************************************************
Link: https://codeforces.com/contest/1512/problem/G
Code: 1512G
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-00.49.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
int sumdiv[MAX + 5];
int res[MAX + 5];

void sieve(){
    for(int i = 1; i * i <= MAX; ++i){
        for(int j = i * i; j <= MAX; j += i){
            sumdiv[j] += i;
            if(i * i != j) sumdiv[j] += j / i;
        }
    }

    for(int i = 1; i <= MAX; ++i){
        if(sumdiv[i] <= MAX && res[sumdiv[i]] == 0){
            res[sumdiv[i]] = i;
        }
    }
}

void solve(){
    int n;
    cin >> n;

    cout << (res[n] == 0 ? -1 : res[n]) << '\n';

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
