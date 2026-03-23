#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[19][2][11][2];
int num[19];

int solve(int idx, int smaller, int cur, int sf){
    if(idx < 0) return sf == 1;

    int &memo = dp[idx][smaller][cur][sf];
    if(memo != -1){
        return memo;
    }

    int limit = smaller == 1 ? 9 : num[idx];

    memo = 0;
    for(int digit = 0; digit <= limit; ++digit){
        if(sf){
            if(digit != cur) memo += solve(idx - 1, smaller || (digit < limit), digit, sf);
        }
        else memo += solve(idx - 1, smaller || (digit < limit), digit, digit != 0);
    }

    return memo;
}

int get(int R){
    if(R < 0) return 0;
    if(R == 0) return 1;

    int len = 0;
    while(R > 0){
        num[len++] = R % 10;
        R /= 10;
    }

    memset(dp, -1, sizeof dp);
    return solve(len - 1, 0, 10, 0) + 1;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int L, R;
    cin >> L >> R;

    cout << get(R) - get(L - 1) << '\n';

    return 0;
}
