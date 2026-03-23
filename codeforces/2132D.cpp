/******************************************************************************
Link: https://codeforces.com/contest/2132/problem/D
Code: 2132D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-14.50.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[16][2][136];
int num[16];
int Try(int idx, int smaller, int sum){
    if(idx < 0){
        return sum;
    }

    int& memo = dp[idx][smaller][sum];
    if(memo != -1) return memo;

    int lim = smaller ? 9 : num[idx];

    memo = 0;
    for(int digit = 0; digit <= lim; ++digit){
        memo += Try(idx - 1, smaller || (digit < lim), sum + digit);
    }

    return memo;
}

string toString(int s){
    string res = "";
    while(s > 0){
        res += s % 10 + '0';
        s /= 10;
    }
    reverse(begin(res), end(res));

    return res;
}

void solve(){
    int k;
    cin >> k;

    int digit = 1, pow10 = 1;
    int cnt = 0;
    while(k > 9 * pow10 * digit){
        k -= 9 * pow10 * digit;
        cnt += 9 * pow10;

        ++digit;
        pow10 *= 10;
    }

    cnt += (k - 1) / digit + 1;
    int pos = (k - 1) % digit + 1;

    string remain = toString(cnt).substr(0, pos);
    int ans = 0;
    for(int i = 0; i < pos; ++i) ans += remain[i] - '0';

    int temp = cnt - 1, len = 0;
    while(temp > 0){
        num[len++] = temp % 10;
        temp /= 10;
    }

    memset(dp, -1, sizeof dp);
    ans += Try(len - 1, 0, 0);

    cout << ans << '\n';
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
