/******************************************************************************
Link: https://codeforces.com/problemset/problem/1766/B
Code: 1766B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-21.09.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<int, int> hashes;
    int prv = -1;
    for(int i = 1; i < n; ++i){
        int h = ((s[i - 1] - 'a') * 26 + (s[i] - 'a'));

        if((prv != h && hashes[h] > 0) || (prv == h && hashes[h] > 1)){
            cout << "YES\n";
            return;
        }
        ++hashes[h];

        prv = h;
    }

    cout << "NO\n";
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
