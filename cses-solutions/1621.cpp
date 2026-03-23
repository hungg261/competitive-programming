#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(begin(arr), end(arr));

    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(arr[i - 1] != arr[i]){
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}
