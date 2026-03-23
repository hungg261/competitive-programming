#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int first = arr[0];
    sort(begin(arr), end(arr));

    int idx = find(begin(arr), end(arr), first) - begin(arr);
    for(int i = idx; i < n; ++i){
        if(first < arr[i]){
            first += (arr[i] - first + 1) / 2;
        }
    }

    cout << first << '\n';
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
