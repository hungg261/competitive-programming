/******************************************************************************
Link: https://codeforces.com/problemset/problem/1926/E
Code: 1926E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-23.30.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    if(k <= (n + 1) / 2){
        cout << k * 2 - 1 << '\n';
        return;
    }

    k -= (n + 1) / 2;
    for(int bit = 1; bit <= 50; ++bit){
        int st = 1LL << bit;
        if(k <= (n - st) / (2 * st) + 1){
            cout << st + (k - 1) * (2 * st) << '\n';
            return;
        }

        k -= (n - st) / (2 * st) + 1;
    }

    cout << "-1\n";
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
