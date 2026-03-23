/******************************************************************************
Link: https://codeforces.com/problemset/problem/2044/E
Code: 2044E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-05-20.56.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e14;

void solve(){
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    auto cnt = [](int kn, int a, int b, int l, int r){
        return max(0LL, min(r, b / kn) - max(l, (a + kn - 1) / kn) + 1);
    };

    int kn = 1;
    int res = 0;
    while(kn <= MAX){
        res += cnt(kn, l2, r2, l1, r1);
        kn *= k;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
