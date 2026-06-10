#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    int ans = 0;
    while(arr.size() > 1){
        int maxPos = min_element(begin(arr) + 1, end(arr)) - begin(arr);

        ans += min(maxPos - 1, n - maxPos);
        arr.erase(begin(arr) + maxPos);
        --n;
    }

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
