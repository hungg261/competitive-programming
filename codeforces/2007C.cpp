#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for(int &ele: arr) cin >> ele;

    int d = __gcd(a, b);
    for(int &ele: arr) ele %= d;

    sort(begin(arr), end(arr));
    int ans = arr.back() - arr[0];
    for(int i = 0; i < n - 1; ++i){
        ans = min(ans, arr[i] + d - arr[i + 1]);
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
