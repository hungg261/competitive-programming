/******************************************************************************
Link: https://codeforces.com/contest/2169/problem/D2
Code: 2169D2
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-07-13.33.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e12;
int x, y, k;

void solve(){
    cin >> x >> y >> k;

    int len = MAX;
    for(int turn = 1; turn <= x;){
        int cur = len / y;
        if(cur == 0) break;

        int L = cur * y;
        int removed = min(x - turn + 1, (len - L) / cur + 1);

        len -= removed * cur;
        turn += removed;
    }

    if(len < k){
        cout << "-1\n";
        return;
    }

    int res = k;
    for(int turn = 1; turn <= x;){
        int cur = (res - 1) / (y - 1);
        if(cur == 0) break;

        int R = (cur + 1) * (y - 1);
        int added = min(x - turn + 1, (R - res) / cur + 1);

        res += cur * added;
        turn += added;
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
