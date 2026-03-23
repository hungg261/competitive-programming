/******************************************************************************
Link: https://codeforces.com/contest/2184/problem/D
Code: 2184D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-11.55.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int nCk[55][55];
void compute(){
    nCk[0][0] = 1;
    for(int i = 1; i <= 50; ++i){
        nCk[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            nCk[i][j] = nCk[i - 1][j] + nCk[i - 1][j - 1];
        }
    }
}

int C(int n, int k){
    if(n < 0 || k < 0) return 0;
    return nCk[n][k];
}

int count1(int len, int target){
    int res = 0;
    for(int b = target + 1; b <= 30; ++b){
        res += C(len - 1, b - 1);
    }
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;

    const int LG = __lg(n);
    int res = 0;
    for(int len = LG; len >= 1; --len){
        res += count1(len, k - len + 1);
    }
    if(__builtin_popcount(n) > k - LG) ++res;

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
