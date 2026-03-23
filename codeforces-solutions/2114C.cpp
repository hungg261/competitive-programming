#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int prv = arr[0];
    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(prv + 1 >= arr[i]){
            continue;
        }
        else{
            prv = arr[i];
            ++ans;
        }
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
