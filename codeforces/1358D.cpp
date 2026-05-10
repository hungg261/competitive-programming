/******************************************************************************
Link: https://codeforces.com/contest/1358/problem/D
Code: 1358D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-06.55.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
int n, x;
int d[MAXN * 2 + 5], pre[MAXN * 2 + 5], presum[MAXN * 2 + 5];

pair<int, int> find_last(int i, int pos){
    assert(1 <= pos && pos <= d[i]);
    int target = pre[i - 1] + pos + x - 1;

    int res = lower_bound(pre + i, pre + n * 2 + 1, target) - pre;

    return {res, target - pre[res - 1]};
}

inline int sum(int l, int r){ return (l + r) * (r - l + 1) / 2; }

void solve(){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int l = 1, r = d[i], res = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            pair<int, int> last = find_last(i, mid);

            if(mid <= last.second + 1){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        pair<int, int> nxt = find_last(i, res);
        int total = nxt.first == i ? sum(res, nxt.second) : (presum[nxt.first - 1] - presum[i]) + sum(res, d[i]) + sum(1, nxt.second);

        ans = max(ans, total);
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> d[i];
        d[i + n] = d[i];
    }

    for(int i = 1; i <= n * 2; ++i){
        pre[i] = pre[i - 1] + d[i];
        presum[i] = presum[i - 1] + sum(1, d[i]);
    }

    solve();

    return 0;
}
