/******************************************************************************
Link: https://codeforces.com/contest/2162/problem/E
Code: 2162E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-18.25.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    multiset<pair<int, int>> ms;
    vector<int> last(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        last[cur] = i;
    }
    for(int ele = 1; ele <= n; ++ele)
        ms.insert({last[ele], ele});

    for(int i = n + 1; k--; ){
        int cur = ms.begin()->second;
        cout << cur << ' ';

        ms.erase(ms.begin());
        ms.insert({i, cur});
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
