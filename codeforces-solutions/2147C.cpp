/******************************************************************************
Link: https://codeforces.com/problemset/problem/2147/C
Code: 2147C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-05-10.09.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto check = [&](int l, int r){
         for(int i = l + 1; i <= r; ++i){
            if(s[i] == s[i - 1]) return true;
         }

         if(s[l] == '0') return true;
         if(s[r] == '0') return true;
         if(l > r) return true;

         int zcnt = 0;
         for(int i = l; i <= r; ++i){
            if(s[i] == '0') ++zcnt;
         }

         return zcnt % 2 == 0;
    };

    int last = 0;
    for(int i = 1; i <= n; ++i){
        if(i == n || (s[i - 1] == '1' && s[i] == '1')){
            if(!check(last, i - 1)){
                cout << "NO\n";
                return;
            }

            last = i;
        }
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
