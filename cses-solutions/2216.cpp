#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<bool> mark(n + 1, false);
    vector<int> arr(n);
    for(int& ele: arr) cin >> ele;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(!mark[arr[i] - 1]) ++ans;
        mark[arr[i]] = true;
    }

    cout << ans << '\n';

    return 0;
}
