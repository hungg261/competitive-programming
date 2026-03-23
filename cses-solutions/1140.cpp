#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<array<int, 3>> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(begin(arr) + 1, end(arr), [](auto& u, auto&v){ return u[1] < v[1] || (u[1] == v[1] && u[0] < v[0]); });

    vector<long long> dp(n + 1);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){

        int idx = lower_bound(begin(arr), begin(arr) + i, arr[i][0], [](auto& u, auto& val){ return u[1] < val; }) - begin(arr);
        --idx;

        dp[i] = max(dp[i - 1], dp[idx] + arr[i][2]);
    }

    cout << dp[n] << '\n';

    return 0;
}
