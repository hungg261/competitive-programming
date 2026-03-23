#include<bits/stdc++.h>
#define int long long
using namespace std;

int len, num[16], n;

int dp[16][2][16 * 9];
int solve(int idx, int smaller, int sum){
    if(idx < 0) return sum;
    
    int &memo = dp[idx][smaller][sum];
    if(memo != -1){
        return memo;
    }
    
    int limit = smaller == 1 ? 9 : num[idx];
    
    memo = 0;
    for(int digit = 0; digit <= limit; ++digit){
        memo += solve(idx - 1, smaller || (digit < limit), sum + digit);
    }
    
    return memo;
}

int get(int R){
    len = 0;
    while(R > 0){
        num[len++] = R % 10;
        R /= 10;
    }
    
    memset(dp, -1, sizeof(dp));
    return solve(len - 1, 0, 0);
}

int get_ans(int l, int r){
    return get(r) - get(l - 1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b;
    cin >> a >> b;
    
    cout << get_ans(a, b) << '\n';
    
    return 0;
}
