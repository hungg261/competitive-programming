/******************************************************************************
Link: https://codeforces.com/gym/105674/problem/B
Code: Gym_105674B
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-01-13.00.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string S;

bool check(){
    bool hasp = false;
    for(const char& c: S){
        if(!(c == '1' || c == '2' || c == '3' || c == '5' || c == '7'))
            return false;
        else if(c != '1'){
            if(hasp) return false;
            hasp = true;
        }
    }

    return hasp;
}

int dp[1000005][2][2][2];
int Try(int idx, int smaller, int hasp, int hasnz){
    if(idx < 0) return hasnz && hasp;

    int &memo = dp[idx][smaller][hasp][hasnz];
    if(memo != -1) return memo;

    int lim = smaller ? 9 : S[idx] - '0';

    memo = 0;
    for(int d: {0, 1, 2, 3, 5, 7}){
        if(d > lim || (hasp && d > 1)) break;
        if(hasnz && d == 0) continue;

        memo += Try(idx - 1, smaller || (d < lim), hasp || d > 1, hasnz || d != 0);
    }
    return memo;
}

int solve(){
    int len = S.size();
    reverse(begin(S), end(S));
    memset(dp, -1, sizeof dp);

    return Try(len - 1, 0, 0, 0);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> S;

    int res = 0;
    res += -solve();
    res += check();

    cin >> S;

    res += solve();

    cout << res << "\n";

    return 0;
}
