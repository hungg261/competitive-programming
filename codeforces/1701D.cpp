/******************************************************************************
Link: https://codeforces.com/problemset/problem/1701/D
Code: 1701D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-15-10.44.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
pair<int, int> find_range(int a, int c, int n){
    if (c <= 0) return {a + 1, n};
    return {a / (c + 1) + 1, a / c};
}

void solve(){
    int n;
    cin >> n;

    vector<int> b(n + 1);
    vector<vector<pair<int, int>>> nxt(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> b[i];

        int l, r; tie(l, r) = find_range(i, b[i], n);
        nxt[l].push_back({r, i});
    }

    set<pair<int, int>> R;
    vector<int> res(n + 1);
    for(int v = 1; v <= n; ++v){
        for(const auto& p: nxt[v]){
            R.insert(p);
        }

        while(!R.empty() && R.begin()->first < v) R.erase(R.begin());
        res[R.begin()->second] = v;
        R.erase(R.begin());
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
    cout << "\n";
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
