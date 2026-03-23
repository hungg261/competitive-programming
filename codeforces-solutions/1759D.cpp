/******************************************************************************
Link: https://codeforces.com/problemset/problem/1759/D
Code: 1759D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-18.54.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    int temp = n;

    int cnt2 = 0, cnt5 = 0;
    while(temp % 2 == 0) temp /= 2, ++cnt2;
    while(temp % 5 == 0) temp /= 5, ++cnt5;

    int cur = 1;
    int ncnt2 = 0, ncnt5 = 0;
    while(cur <= m){
        bool changed = false;
        if(cur * 2 <= m && cnt2 <= cnt5) cur *= 2, ++cnt2, ++ncnt2, changed = true;
        if(cur * 5 <= m && cnt5 < cnt2) cur *= 5, ++cnt5, ++ncnt5, changed = true;

        if(!changed) break;
    }

    while(cnt2 > cnt5 && cur % 2 == 0) cur /= 2, --cnt2;
    while(cnt5 > cnt2 && cur % 5 == 0) cur /= 5, --cnt5;

    cur = cur * (m / cur);
    int res = n * cur;

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
