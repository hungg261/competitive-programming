/******************************************************************************
Link: https://codeforces.com/problemset/problem/1603/B
Code: 1603B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-19.27.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x, y;
    cin >> x >> y;

    int n;
    if(x > y){
        n = x + y;
    }
    else{
        n = y - (y % x) / 2;
    }

    cout << n << '\n';
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1e9;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}
