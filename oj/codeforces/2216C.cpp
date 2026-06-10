/******************************************************************************
Link: https://codeforces.com/contest/2216/problem/C
Code: 2216C
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-29-15.09.23
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k, p, q;
    cin >> n >> k >> p >> q;

    vector<int> a(n + 1), pre(n + 1), pq(n + 1), qp(n + 1);
    pre[0] = pq[0] = qp[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];

        int _pq = a[i] % p % q, _qp = a[i] % q % p;
        pre[i] = pre[i - 1] + min(_pq, _qp);
        pq[i] = pq[i - 1] + _pq;
        qp[i] = qp[i - 1] + _qp;
    }

    int res = LLONG_MAX;
    for(int i = 1; i + k - 1 <= n; ++i){
        int j = i + k - 1;

        res = min(res, min(pq[j] - pq[i - 1], qp[j] - qp[i - 1]) + pre[i - 1] + pre[n] - pre[j]);
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
