/******************************************************************************
Link: https://codeforces.com/contest/1627/problem/D
Code: 1627D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-04-15.35.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXVAL = 1e6;
int n, a[MAXN + 5];
bool cnt[MAXVAL + 5];

void solve(){
    int res = 0;
    for(int i = 1; i <= MAXVAL; ++i){
        int cur = 0;
        for(int j = i; j <= MAXVAL; j += i){
            if(cnt[j]) cur = __gcd(cur, j);
        }

        if(cur == i) ++res;
    }

    cout << res - n << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]] = true;
    }

    solve();

    return 0;
}
