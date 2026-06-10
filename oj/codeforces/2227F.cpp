/******************************************************************************
Link: https://codeforces.com/contest/2227/problem/F
Code: 2227F
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-30-21.58.19
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int sum(int l, int r){ if(l > r) return 0; return (l + r) * (r - l + 1) / 2; }

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> suf_cnt(n + 2), suf_sum(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        suf_cnt[a[i]]++;
        suf_sum[a[i]] += i;
    }

    vector<int> maxR(n + 2, 0);
    int curH = 1e9;
    for(int i = n; i >= 1; --i){
        curH = min(curH, a[i]);

        maxR[1]++;
        maxR[curH + 1]--;
    }

    suf_cnt[n + 1] = suf_sum[n + 1] = 0;
    for(int h = n; h >= 1; --h){
        suf_cnt[h] += suf_cnt[h + 1];
        suf_sum[h] += suf_sum[h + 1];
    }

    int total = 0;
    for(int h = 1; h <= n; ++h){
        maxR[h] += maxR[h - 1];

        int cnt = suf_cnt[h] - maxR[h];
        total += sum(n - maxR[h] - cnt + 1, n - maxR[h]) - (suf_sum[h] - sum(n - maxR[h] + 1, n));
    }

    int res = total;

    for(int i = 1; i <= n; ++i){
        int ri = n - i + 1;

        if(ri <= maxR[a[i]]){
            int cur = total;
            int h = a[i];

            int cnt = suf_cnt[h] - maxR[h];
            cur -= sum(n - maxR[h] - cnt + 1, n - maxR[h]) - (suf_sum[h] - sum(n - maxR[h] + 1, n));

            int mR = n - i;
            cnt = suf_cnt[h] - mR - 1;

            cur += sum(n - mR - cnt + 1, n - mR) - (suf_sum[h] - sum(n - mR, n));

            res = max(res, cur);
        }
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
