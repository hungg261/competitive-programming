/******************************************************************************
Link: https://codeforces.com/problemset/problem/2053/B
Code: 2053B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-17.54.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> it(n);
    vector<int> point(n * 2 + 1, 0);
    for(int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;

        it[i] = {l, r};
        if(l == r){
            point[l]++;
        }
    }

    vector<int> pref(n * 2 + 1);
    pref[0] = 0;
    for(int i = 1; i <= n * 2; ++i){
        pref[i] = pref[i - 1] + (point[i] > 0);
    }

    for(int i = 0; i < n; ++i){
        int l, r;
        tie(l, r) = it[i];

        if(l == r){
            if(point[l] > 1) cout << "0";
            else cout << "1";
            continue;
        }

        if(pref[r] - pref[l - 1] == r - l + 1){
            cout << "0";
        }
        else cout << "1";

    }
    cout << '\n';
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
