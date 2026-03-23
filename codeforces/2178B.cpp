/******************************************************************************
Link: https://codeforces.com/contest/2178/problem/B
Code: 2178B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-09.15.43
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int sz = s.size();
    int res = 0;
    for(int i = 0; i < sz; ++i){
        if(s[i] == 'u'){
            if(i == 0 || i == sz - 1){
                s[i] = 's';
                ++res;
            }
            else{
                if(s[i - 1] == 'u') s[i - 1] = 's', ++res;
                if(s[i + 1] == 'u') s[i + 1] = 's', ++res;
            }
        }
    }

    cout << res << '\n';
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
