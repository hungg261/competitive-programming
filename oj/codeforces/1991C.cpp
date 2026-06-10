/******************************************************************************
Link: https://codeforces.com/problemset/problem/1991/C
Code: 1991C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-05-17.32.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    bool ok = true;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(i > 0 && llabs(arr[i] - arr[i - 1]) % 2 != 0) ok = false;
    }

    if(!ok){
        cout << "-1\n";
        return;
    }

    auto is_eq = [&](){
        return *min_element(begin(arr), end(arr)) == *max_element(begin(arr), end(arr));
    };

    vector<int> res;
    auto op = [&](int x){
        res.push_back(x);
        for(int& ele: arr) ele = llabs(ele - x);
    };

    int mx = *max_element(begin(arr), end(arr));
    if(mx != 0) op(mx - (1LL << __lg(mx)));

    while(!is_eq()){
        int x = *max_element(begin(arr), end(arr));
        op(x / 2);
    }
    op(arr[0]);

    cout << res.size() << '\n';
    for(int o: res) cout << o << ' '; cout << '\n';
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
