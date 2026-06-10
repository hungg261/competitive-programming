#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        int temp = i;

        dp[i] = LLONG_MAX >> 1;
        while(temp > 0){
            dp[i] = min(dp[i], dp[i - temp % 10] + 1);
            temp /= 10;
        }
    }

    for(int idx = 0; idx <= n; ++idx){
        cout << idx << ": " << dp[idx] << '\n';
    }

    return 0;
}
