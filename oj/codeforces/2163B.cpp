/******************************************************************************
Link: https://codeforces.com/contest/2163/problem/B
Code: 2163B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-11.57.13
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    int minPos = min_element(begin(p) + 1, end(p)) - begin(p);
    int maxPos = max_element(begin(p) + 1, end(p)) - begin(p);

    string s;
    cin >> s;
    s = " " + s;

    if(s[1] == '1' || s[n] == '1' || s[minPos] == '1' || s[maxPos] == '1'){
        cout << "-1\n";
        return;
    }

    if(minPos > maxPos) swap(minPos, maxPos);

    cout << "5\n";
    cout << 1 << ' ' << minPos << '\n';
    cout << 1 << ' ' << maxPos << '\n';
    cout << minPos << ' ' << n << '\n';
    cout << maxPos << ' ' << n << '\n';
    cout << minPos << ' ' << maxPos << '\n';
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
