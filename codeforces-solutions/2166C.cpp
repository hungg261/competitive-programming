#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int ans = max(arr[0], arr[n - 1]), maxVal = arr[0];
    for(int i = 1; i < n; ++i){
        ans += max(arr[i - 1], arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    ans -= maxVal;
    cout << ans << '\n';
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
