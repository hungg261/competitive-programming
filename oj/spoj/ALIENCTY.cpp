/******************************************************************************
Link: https://www.spoj.com/problems/ALIENCTY/en
Code: ALIENCTY
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-24-17.05.01
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1e5;
int n;
int x[MAXN + 5], y[MAXN + 5], z[MAXN + 5];

void solve(){
    int ans = 0;
    for(int mask = 0; mask < 8; ++mask){
        int mn = INF, mx = -INF;
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            if(mask & 1) cur += x[i];
            else cur -= x[i];
            if(mask & 2) cur += y[i];
            else cur -= y[i];
            if(mask & 4) cur += z[i];
            else cur -= z[i];

            mn = min(mn, cur);
            mx = max(mx, cur);
        }

        ans = max(ans, mx - mn);
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> z[i];

    solve();

    return 0;
}
