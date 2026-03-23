/******************************************************************************
Link: https://codeforces.com/problemset/problem/1926/D
Code: 1926D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-17-22.44.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<bool> mark(n, false);
    multiset<int> arr;
    for(int i = 0; i < n; ++i){
        int cur; cin >> cur;
        arr.insert(cur);
    }

    int res = n;
    while(!arr.empty()){
        int target = (~*arr.begin()) ^ (1 << 31);
        arr.erase(arr.begin());

        auto it = arr.find(target);
        if(it == arr.end()) continue;

        arr.erase(it);
        --res;
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
