/******************************************************************************
Link: https://cses.fi/problemset/task/1146
Code: 1146
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-25-10.15.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(int N, int bitpos){
    int cycle = 1LL << (bitpos + 1);
    int rep = N >> (bitpos + 1);
    int cnt = rep << bitpos;

    return cnt + max(0LL, (N & (cycle - 1)) - (1LL << bitpos) + 1);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1146.INP","r",stdin);
    //freopen("1146.OUT","w",stdout);

    int n;
    cin >> n;

    int ans = 0;
    for(int bit = 0; bit <= 60; ++bit){
        ans += solve(n, bit);
    }

    cout << ans << '\n';

    return 0;
}
