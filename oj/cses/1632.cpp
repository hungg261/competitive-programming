#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for(auto& p: arr) cin >> p.first >> p.second;
    sort(begin(arr), end(arr), [](pair<int, int>&u, pair<int, int>& v){ return (u.second == v.second && u.first < v.first) || u.second < v.second; });

    multiset<int, greater<int>> ms;
    for(int i = 1; i <= k; ++i) ms.insert(0);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        auto pos = ms.lower_bound(arr[i].first);
        if(pos != ms.end()){
            ++ans;
            ms.erase(pos);
            ms.insert(arr[i].second);
        }
    }

    cout << ans << '\n';

    return 0;
}
