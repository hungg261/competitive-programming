#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n * 2 + 1);
    for(int i = 1; i <= n * 2; ++i){
        cin >> arr[i];
    }

    sort(begin(arr) + 1, end(arr), greater<int>());

    vector<int> res(n * 2 + 2);
    int idx = 0;
    int missing = 0;
    for(int i = 1; i <= n * 2 + 1; i += 2){
        res[i] = arr[++idx];
        missing += res[i];
    }
    for(int i = 2; i <= n * 2 - 2; i += 2){
        res[i] = arr[++idx];
        missing -= res[i];
    }
    res[n * 2] = missing;

    for(int i = 1; i <= n * 2 + 1; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
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
