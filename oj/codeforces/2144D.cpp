/******************************************************************************
Link: https://codeforces.com/contest/2144/problem/D
Code: 2144D
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-26-13.40.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 2e5;
void brute(){
    int n, y;
    cin >> n >> y;

    vector<int> c(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    auto Try = [&](int x){
        vector<int> temp = c;
        map<int, int> mp;
        for(int i = 1; i <= n; ++i){
            mp[temp[i]]++;
        }

        int res = 0;
        for(int i = 1; i <= n; ++i){
            temp[i] = (temp[i] + x - 1) / x;
            res += temp[i];

            if(--mp[temp[i]] < 0) res -= y;
        }

        return res;
    };

    for(int x = 2; x <= 200; ++x){
        cerr << x << ": " << Try(x) << "\n";
    }
}

void solve(){
    int n, y;
    cin >> n >> y;

    vector<int> c(n + 1);
    int mx = -1e18;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
        mx = max(mx, c[i]);
    }

    if(mx == 1){
        cout << n << "\n";
        return;
    }

    vector<int> pre(mx + 1, 0), mp(mx + 1, 0);
    for(int i = 1; i <= n; ++i) pre[c[i]] = ++mp[c[i]];
    for(int i = 1; i <= mx; ++i) pre[i] += pre[i - 1];

    int ans = -1e18;
    for(int x = 2; x <= mx; ++x){
        int res = 0;
        for(int j = 1; (j - 1) * x + 1 <= mx; ++j){
            int L = (j - 1) * x + 1, R = min(mx, j * x);

            int need = pre[R] - pre[L - 1];
            int left = max(0LL, need - mp[j]);
            res += j * need - left * y;

        }

        ans = max(ans, res);
    }

    cout << ans << "\n";
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
