/******************************************************************************
Link: https://dmoj.ca/problem/apio07p2
Code: apio07p2
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-18-22.28.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, INF = 1e18;
int n, k, w[MAXN + 5];

int L[MAXN + 5], R[MAXN + 5], del[MAXN + 5];
void solve(){
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    w[0] = w[n + 1] = INF;
    for(int i = 1; i <= n; ++i){
        L[i] = i - 1;
        R[i] = i + 1;
        pq.push({w[i], i});
    }

    int ans = 0;
    for(int s = 0; s < k; ++s){
        while(!pq.empty() && del[pq.top().second]){
            pq.pop();
        }

        int val, idx; tie(val, idx) = pq.top();
        pq.pop();

        ans += val;

        int l = L[idx], r = R[idx];
        w[idx] = w[l] + w[r] - val;
        pq.push({w[idx], idx});

        del[l] = del[r] = true;
        if(1 <= l){
            L[idx] = L[l];
            R[L[l]] = idx;
        }
        if(r <= n){
            R[idx] = R[r];
            L[R[r]] = idx;
        }
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> w[i];

    for(int i = 1; i + 1 <= n; ++i){
        w[i] = w[i + 1] - w[i];
    }
    n = n - 1;

    solve();

    return 0;
}
