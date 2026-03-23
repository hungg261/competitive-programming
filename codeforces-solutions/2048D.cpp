/******************************************************************************
Link: https://codeforces.com/contest/2048/problem/D
Code: 2048D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-23-08.41.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    int P = a[1];
    a.erase(a.begin() + 1);
    sort(begin(a) + 1, end(a));
    sort(begin(b) + 1, end(b));

    vector<int> solved(m + 1);
    for(int i = m; i >= 1; --i){
        solved[i] = end(a) - lower_bound(begin(a) + 1, end(a), b[i]);
    }

    int pos = upper_bound(begin(b) + 1, end(b), P) - begin(b) - 1;
    for(int k = 1; k <= m; ++k){
        int res = 0;
        res += pos / k;

        int left = k - pos % k;
        for(int i = m - left + 1; i > pos; i -= k){
            res += solved[i] + 1;
        }

        cout << res << ' ';
    }
    cout << '\n';
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
