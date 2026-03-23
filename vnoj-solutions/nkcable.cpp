#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    
    vector<int> arr(n + 1), dp(n + 1);
    for(int i = 2; i <= n; ++i) cin >> arr[i];
    
    if(n == 2){
        cout << arr[2] << '\n';
        return 0;
    }
    
    arr[1] = 0;
    dp[0] = 0; dp[1] = 1e9;
    for(int i = 2; i <= n; ++i){
        dp[i] = min(dp[i - 1] + arr[i], dp[i - 2] + arr[i]);
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}
