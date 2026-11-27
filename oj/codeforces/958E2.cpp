/******************************************************************************
Link: https://codeforces.com/problemset/problem/958/E2
Code: 958E2
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-26-23.28.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5, INF = 1e14;
int k, n, t[MAXN + 5];
int L[MAXN + 5], R[MAXN + 5], del[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n;

    for(int i = 1; i <= n; ++i){
        cin >> t[i];
    }
    sort(t, t + n + 1);

    for(int i = 1; i + 1 <= n; ++i){
        t[i] = t[i + 1] - t[i];
    }
    n--;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 1; i <= n; ++i){
        L[i] = i - 1;
        R[i] = i + 1;

        pq.push({t[i], i});
    }

    t[0] = INF;
    t[n + 1] = INF;

    int ans = 0;
    for(int j = 0; j < k; ++j){
        while(!pq.empty() && del[pq.top().second]) pq.pop();

        int val, idx; tie(val, idx) = pq.top(); pq.pop();
        ans += val;

        int le = L[idx], ri = R[idx];
        t[idx] = t[le] + t[ri] - val;
        pq.push({t[idx], idx});

        del[le] = del[ri] = true;

        if(le >= 1){
            L[idx] = L[le];
            R[L[le]] = idx;
        }
        if(ri <= n){
            R[idx] = R[ri];
            L[R[ri]] = idx;
        }
    }

    cout << ans << "\n";

    return 0;
}
