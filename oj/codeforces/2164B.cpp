#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(begin(arr), end(arr));
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[j] % arr[i] % 2 == 0){
                cout << arr[i] << ' ' << arr[j] << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
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
