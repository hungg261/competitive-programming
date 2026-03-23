/******************************************************************************
Link: https://codeforces.com/contest/319/problem/C
Code: 319C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-10.41.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int a[MAXN + 5], b[MAXN + 5], n;
int dp[MAXN + 5];

int w(int j, int i){
    return b[j] * a[i];
}

void trau(){
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            dp[i] = min(dp[i], dp[j] + b[j] * a[i]);
        }
    }

    cout << dp[n] << '\n';
}

struct Range{
    int l, r, p;

    tuple<int, int, int> get(){
        return {l, r, p};
    }
};

void solve(){
    deque<Range> dq;
    dq.push_front({2, n, 1});

    for(int i = 2; i <= n; ++i){
        Range& cur = dq.front();
        dp[i] = dp[cur.p] + w(cur.p, i);

        ++cur.l;
        if(cur.l > cur.r) dq.pop_front();

        while(!dq.empty()){
            int l, r, p;
            tie(l, r, p) = dq.back().get();

            if(dp[i] + w(i, l) < dp[p] + w(p, l)) dq.pop_back();
            else break;
        }

        if(dq.empty()){
            dq.push_front({i + 1, n, i});
            continue;
        }

        int l, r, p;
        tie(l, r, p) = dq.back().get();
        int pos = r + 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(dp[i] + w(i, mid) < dp[p] + w(p, mid)){
                pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        dq.back().r = pos - 1;
        if(pos <= n) dq.push_back({pos, n, i});
    }

    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    solve();

    return 0;
}
