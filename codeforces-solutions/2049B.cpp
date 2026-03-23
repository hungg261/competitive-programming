/******************************************************************************
Link: https://codeforces.com/problemset/problem/2049/B
Code: 2049B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-23.15.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    string temp; temp += s[0];
    for(int i = 1; i < n - 1; ++i) if(s[i] != '.') temp += s[i];
    if(n > 1) temp += s[n - 1];

    s = temp;
    n = s.size();

    int pcnt = 0, scnt = 0, dcnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 's' && pcnt > 0){
            cout << "NO\n";
            return;
        }
        if(i - 2 >= 0 && i + 1 < n && s[i - 1] == 's' && s[i] == 'p'){
            cout << "NO\n";
            return;
        }

        if(s[i] == 'p') ++pcnt;
        else if(s[i] == 's') ++scnt;
        else ++dcnt;
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
