#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7 ;
int len, num[10001], n, D;

int dp[10001][2][101];
int solve(int idx, int smaller, int sum){
    if(idx < 0){
        return sum % D == 0;
    }
    
    int &memo = dp[idx][smaller][sum];
    if(memo != -1){
        return memo;
    }
    
    int limit = smaller == 1 ? 9 : num[idx];
    
    memo = 0;
    for(int digit = 0; digit <= limit; ++digit){
        (memo += solve(idx - 1, smaller || (digit < limit), (sum + digit) % D)) %= MOD;
    }
    
    return memo % MOD;
}

int get(string R){
    len = 0;
    while(!R.empty()){
        num[len++] = R.back() - '0';
        R.pop_back();
    }
    
    memset(dp, -1, sizeof(dp));
    return solve(len - 1, 0, 0);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string r;
    cin >> r >> D;
    
    cout << ((get(r) - 1) % MOD + MOD) % MOD << '\n'; 
    
    return 0;
}
