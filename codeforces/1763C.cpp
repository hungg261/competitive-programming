/******************************************************************************
Link: https://codeforces.com/contest/1763/problem/C
Code: 1763C
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-15-08.22.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    int mx_idx = max_element(begin(a), end(a)) - begin(a);

    if(n == 2){
        cout << max(sum, 2LL * abs(a[0] - a[1])) << "\n";
    }
    else if(n == 3){
        long long ans = sum;
        ans = max(ans, 3LL * abs(a[0] - a[1]));
        ans = max(ans, 3LL * abs(a[1] - a[2]));
        ans = max(ans, 3LL * abs(a[0] - a[2]));
        ans = max(ans, 3LL * a[0]);
        ans = max(ans, 3LL * a[2]);
        ans = max(ans, a[0] + 2LL * abs(a[1] - a[2]));
        ans = max(ans, a[2] + 2LL * abs(a[0] - a[1]));

        cout << ans << "\n";
    }
    else cout << 1LL * a[mx_idx] * n << "\n";
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
