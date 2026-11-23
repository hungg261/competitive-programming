/******************************************************************************
Link: https://qoj.ac/problem/2166
Code: 2166
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-23-18.03.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2e5;
int n;
int x[MAXN + 5], y[MAXN + 5], z[MAXN + 5];

void solve(){
    int best[8] = {};
    for(int mask = 0; mask < 8; ++mask){
        for(int i = 1; i <= n; ++i){
            int sum = 0;
            if(mask & 1) sum += x[i];
            if(mask & 2) sum += y[i];
            if(mask & 4) sum += z[i];

            best[mask] = max(best[mask], sum);
        }
    }

    pair<int, int> ans = {INF, INF};
    for(int i = 1; i <= n; ++i){
        int cur = 0;
        for(int mask = 0; mask < 8; ++mask){
            int sum = 0;
            if(mask & 1) sum += x[i];
            if(mask & 2) sum += y[i];
            if(mask & 4) sum += z[i];

            cur = max(cur, best[mask] - sum);
        }

        ans = min(ans, {cur, i});
    }

    cout << ans.first << " " << ans.second << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i] >> z[i];
    }

    solve();

    return 0;
}
