/******************************************************************************
Link: https://codeforces.com/problemset/problem/1872/C
Code: 1872C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-17.48.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAX = 1e7;
int d[MAX + 5];
void sieve(){
    for(int i = 2; i * i <= MAX; ++i){
        if(d[i] == 0){
            for(int j = i * i; j <= MAX; j += i){
                d[j] = i;
            }
        }
    }
}

void solve(){
    int l, r;
    cin >> l >> r;

    if(r <= 3) cout << "-1\n";
    else if(r % 2 == 0 || l < r){
        cout << (r / 2) << ' ' << (r / 2) << '\n';
    }
    else{
        if(d[r] == 0) cout << "-1\n";
        else cout << (d[r]) << ' ' << (r - d[r]) << '\n';
    }
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
