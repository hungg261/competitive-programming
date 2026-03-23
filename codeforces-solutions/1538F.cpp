#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[11][2][2][11];
int num[11];

int Try(int idx, int smaller, int sig, int cnt0){
    if(idx < 0){
        return sig ? cnt0 : 0;
    }

    int &memo = dp[idx][smaller][sig][cnt0];
    if(memo != -1) return memo;

    int lim = smaller ? 9 : num[idx];
    memo = 0;

    for(int digit = 0; digit <= lim; ++digit){
        memo += Try(idx - 1, smaller || (digit < lim), sig || (digit != 0), sig && digit == 0 ? cnt0 + (digit == 0) : 0);
    }
    return memo;
}

int query(int idx){
    int len = 0;
    while(idx > 0){
        num[len++] = idx % 10;
        idx /= 10;
    }

    memset(dp, -1, sizeof dp);
    return Try(len - 1, 0, 0, 0);
}
int query(int l, int r){ return query(r) - query(l - 1); }

void solve(){
    int l, r;
    cin >> l >> r;

    int cnt0 = query(l + 1, r);
    int res = r - l + cnt0;

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
