#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i){
        int u, v; cin >> u >> v;

        a[i] = {v, u};
    }
    sort(begin(a), end(a));

    int last = -1;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(last <= a[i].second){
            ++ans;
            last = a[i].first;
        }
    }

    cout << ans << '\n';

    return 0;
}
