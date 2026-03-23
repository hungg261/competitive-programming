/******************************************************************************
Link: https://codeforces.com/problemset/problem/1891/B
Code: 1891B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-22.54.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n), x;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < q; ++i){
        int xi;
        cin >> xi;

        if(x.empty() || x.back() > xi) x.push_back(xi);
    }

    for(int bit: x){
        for(int i = 0; i < n; ++i){
            if(arr[i] % (1 << bit) == 0){
                arr[i] += 1 << (bit - 1);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
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
