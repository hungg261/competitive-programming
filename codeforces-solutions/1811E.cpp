/******************************************************************************
Link: https://codeforces.com/problemset/problem/1811/E
Code: 1811E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-16.57.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[18][2];
int num[18];

int Try(int idx, int smaller){
    if(idx < 0){
        return 1;
    }

    int& memo = dp[idx][smaller];
    if(memo != -1) return memo;

    int lim = smaller ? 9 : num[idx];
    memo = 0;
    for(int digit = 0; digit <= lim; ++digit){
        if(digit == 4) continue;
        memo += Try(idx - 1, smaller || (digit < lim));
    }

    return memo;
}

int get(int r){
    int len = 0;
    while(r > 0){
        num[len++] = r % 10;
        r /= 10;
    }

    memset(dp, -1, sizeof dp);
    return Try(len - 1, 0) - 1;
}

void solve(){
    int k;
    cin >> k;

    int l = 1, r = 1e17, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(get(mid) >= k){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}
