/******************************************************************************
Link: https://codeforces.com/problemset/problem/1988/B
Code: 1988B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-22.30.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt[2] = {};
    ++cnt[s[0] - '0'];

    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1] || s[i] == '1'){
            ++cnt[s[i] - '0'];
        }
    }

    cout << (cnt[1] > cnt[0] ? "Yes" : "No") << '\n';
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
