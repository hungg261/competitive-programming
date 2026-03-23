/******************************************************************************
Link: https://codeforces.com/contest/2118/problem/D1
Code: 2118D1
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-16.02.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> p(n + 1), d(n + 1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) cin >> d[i];

    auto subsolve = [&](int start){
        vector<vector<bool>> mark(n + 1, vector<bool>(2, false));

        int idx = lower_bound(begin(p) + 1, end(p), start) - begin(p);
        if(idx > n) return true;

        int t = p[idx] - start;
        int delta = 1;

        while(1 <= idx && idx <= n){
            if(t % k == d[idx]){
                delta *= -1;
                if(mark[idx][delta + 1 >> 1]) return false;
                mark[idx][delta + 1 >> 1] = true;
            }


            int nxt = idx + delta;
            if(nxt < 1 || nxt > n) return true;

            t += abs(p[nxt] - p[idx]);
            idx = nxt;
        }

        return true;
    };

    int q;
    cin >> q;

    while(q--){
        int s;
        cin >> s;

        cout << (subsolve(s) ? "YES\n" : "NO\n");
    }
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
