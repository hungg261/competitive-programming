/******************************************************************************
Link: https://codeforces.com/contest/2227/problem/E
Code: 2227E
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-30-21.43.53
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> suf(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        suf[a[i]]++;
    }

    vector<int> maxR(n + 2, 0);
    int curH = 1e9;
    for(int i = n; i >= 1; --i){
        curH = min(curH, a[i]);

        maxR[1]++;
        maxR[curH + 1]--;
    }

    suf[n + 1] = 0;
    for(int h = n; h >= 1; --h){
        suf[h] += suf[h + 1];
    }

    int total = 0;
    for(int h = 1; h <= n; ++h){
        maxR[h] += maxR[h - 1];
        total += suf[h] - maxR[h];
    }

    int res = total;
    for(int i = 1; i <= n; ++i){
        int ri = n - i + 1;

        if(ri <= maxR[a[i]]) res = max(res, total + maxR[a[i]] - ri);
    }

    cout << res << "\n";
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
