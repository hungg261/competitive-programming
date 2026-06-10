/******************************************************************************
Link: https://codeforces.com/problemset/problem/1845/C
Code: 1845C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-12-20.59.52
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    int m;
    string l, r;

    cin >> s;
    cin >> m;
    cin >> l;
    cin >> r;


    int sz = s.size();
    s = "#" + s;

    vector<vector<int>> nxt(sz + 1);

    vector<int> cur(10, sz + 1);
    for(int i = sz; i >= 0; --i){
        nxt[i] = cur;
        if(i > 0) cur[s[i] - '0'] = i;
    }

    int curPos = 0;
    for(int i = 0; i < m; ++i){
        int nxtPos = -1;
        for(int j = l[i] - '0'; j <= r[i] - '0'; ++j){
            nxtPos = max(nxtPos, nxt[curPos][j]);
        }

        curPos = nxtPos;

        if(curPos > sz){
            cout << "YES\n";
            return;
        }
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
