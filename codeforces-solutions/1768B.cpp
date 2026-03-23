#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    map<int, int> mark;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        mark[arr[i]] = i;
    }

    sort(begin(arr), end(arr));
    for(int i = 1; i < n; ++i){
        if(mark[arr[i - 1]] > mark[arr[i]]){
            int ans = (n - i + k - 1) / k;

            cout << ans << '\n';
            return;
        }
    }

    cout << "0\n";
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
