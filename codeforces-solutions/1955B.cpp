/******************************************************************************
Link: https://codeforces.com/problemset/problem/1955/B
Code: 1955B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-22.06.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> arr(n * n);
    for(int i = 0; i < n * n; ++i) cin >> arr[i];

    int base = *min_element(begin(arr), end(arr));
    vector<vector<int>> table(n, vector<int>(n));
    vector<int> values;

    table[0][0] = base;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            values.push_back(table[i][j]);
            if(i + 1 < n) table[i + 1][j] = table[i][j] + c;
            if(j + 1 < n) table[i][j + 1] = table[i][j] + d;
        }
    }

    sort(begin(arr), end(arr));
    sort(begin(values), end(values));

    cout << (arr == values ? "YES" : "NO") << '\n';
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
