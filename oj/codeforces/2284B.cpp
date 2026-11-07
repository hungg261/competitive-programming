/******************************************************************************
Link: https://codeforces.com/contest/2284/problem/B
Code: 2284B
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-06-22.01.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e9;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int max_val = -INF;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    int cnt = count(begin(a), end(a), max_val);
    if(k < cnt){
        cout << "NO\n";
        return;
    }

    sort(begin(a), end(a), greater<int>());
    sort(begin(a), begin(a) + k);

    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";

    {
        int pre = 0, ok = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] * i >= pre) ++ok;
            pre += a[i];
        }
        assert(ok == k);
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
