/******************************************************************************
Link: https://codeforces.com/problemset/problem/1984/B
Code: 1984B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-03-22.38.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int x;
    cin >> x;

    if(to_string(x)[0] != '1'){
        cout << "NO\n";
        return;
    }

    int carry = 0;
    while(x > 0){
        int d = x % 10;
        x /= 10;

        for(int i = 5; i <= 9; ++i){
            for(int j = 5; j <= 9; ++j){
                if((i + j + carry) % 10 == d){
                    carry = 1;
                    goto passed;
                }
            }
        }

        cout << "NO\n";
        return;
        passed: NULL;
    }

    cout << "YES\n";
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
