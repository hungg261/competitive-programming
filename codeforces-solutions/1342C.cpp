/******************************************************************************
Link: https://codeforces.com/contest/1342/problem/C
Code: 1342C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-12-19.06.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a, b, q;
    cin >> a >> b >> q;

    if(a > b) swap(a, b);
    while(q--){
        int l, r;
        cin >> l >> r;

        int res = 0;
        for(int m = 0; m < b; ++m){
            int tlow = llround(ceil(1.0 * (l - m) / a)),
                thigh = llround(floor(1.0 * (r - m) / a));

            tlow = max(0LL, tlow);

            cerr << m << ": " << tlow << ' ' << thigh << '\n';
            res += max(0LL, thigh - tlow + 1);
        }

        cout << res << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
