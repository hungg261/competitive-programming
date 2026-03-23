#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(m + 1);
    vector<int> mark(n + 1, 0);

    for(int i = 1; i <= m; ++i){
        cin >> arr[i];
        ++mark[arr[i]];
    }

    sort(begin(arr), end(arr));

    int ans = 0, suf = mark[n];
    for(int j = n - 1; j >= 1; --j){
        suf += mark[j];

        int idx = lower_bound(begin(arr) + 1, end(arr), n - j) - begin(arr);
        int delta = m - idx + 1;

        ans += delta * suf;
    }

    for(int i = 1; i <= m; ++i){
        int cur = min(n - 1, arr[i]);
        ans -= max(0LL, cur - (n - cur) + 1);
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
