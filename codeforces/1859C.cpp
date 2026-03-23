/******************************************************************************
Link: https://codeforces.com/problemset/problem/1859/C
Code: 1859C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-05-16.44.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    auto getSum2 = [](int r){
        return r * (r + 1) * (2 * r + 1) / 6;
    };

    int best = -1;
    for(int i = n; i >= 1; --i){
        int cur = getSum2(i - 1);
        int idx = i;

        int mx = i * i;
        for(int j = n; j >= i; --j){
            cur += j * idx;
            mx = max(mx, j * idx);
            ++idx;
        }

        best = max(best, cur - mx);
    }

    cout << best << '\n';
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
