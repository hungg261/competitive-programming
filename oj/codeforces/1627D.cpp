/******************************************************************************
Link: https://codeforces.com/contest/1627/problem/D
Code: 1627D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-04-15.16.02
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXVAL = 1e6;
int n, a[MAXN + 5];
unsigned long long cnt[MAXVAL + 5];

void solve(){
    for(int i = 1; i <= MAXVAL; ++i){
        for(int j = i * 2; j <= MAXVAL; j += i){
            cnt[i] += cnt[j];
        }
        cnt[i] = (1LL << cnt[i]) - 1;
    }

    int res = 0;
    for(int i = MAXVAL; i >= 1; --i){
        for(int j = i * 2; j <= MAXVAL; j += i){
            cnt[i] -= cnt[j];
        }

        if(cnt[i]) ++res;
    }

    cout << res - n << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    solve();

    return 0;
}
