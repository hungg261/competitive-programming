#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);

    for(auto& p: arr) cin >> p.first >> p.second;
    sort(begin(arr), end(arr));

    int f = 0, ans = 0;
    for(const auto& p: arr){
        f += p.first;
        ans += p.second - f;
    }

    cout << ans << '\n';

    return 0;
}
