/******************************************************************************
Link: https://codeforces.com/problemset/problem/959/E
Code: 959E
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-20-11.50.57
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(int b, int bound){
    if(b < 0) return 0;
    if((bound & (bound + 1)) == 0){
        int lg = __lg(bound + 1);
        return lg * (1LL << (lg - 1));
    }

    int res = 0;
    res += solve(b - 1, bound & ~(1LL << b));
    if(bound >> b & 1) res += solve(b - 1, (1LL << b) - 1) + (1LL << b);

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    cout << solve(50, n - 1) << "\n";

    return 0;
}
