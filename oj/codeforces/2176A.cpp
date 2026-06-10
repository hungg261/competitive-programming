#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &ele: arr) cin >> ele;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[j] > arr[i]){
                ++ans;
                break;
            }
        }
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
