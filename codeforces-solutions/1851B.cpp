#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    vector<int> temp = arr;
    sort(begin(temp), end(temp));
    for(int i = 0; i < n; ++i){
        if(arr[i] % 2 != temp[i] % 2){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
