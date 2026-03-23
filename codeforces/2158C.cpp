#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> maxPref(n + 1), maxSuf(n + 1);
    maxPref[1] = a[1], maxSuf[n] = a[n];
    for(int i = 2; i <= n; ++i) maxPref[i] = max(a[i], maxPref[i - 1] + a[i]);
    for(int i = n - 1; i >= 1; --i) maxSuf[i] = max(a[i], maxSuf[i + 1] + a[i]);

    int ans = LLONG_MIN;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, maxPref[i] + maxSuf[i] - a[i] + (k & 1 ? b[i] : 0));
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
