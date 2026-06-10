/******************************************************************************
Link: https://codeforces.com/contest/1285/problem/D
Code: 1285D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-10-10.44.22
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

template<typename T> inline void maximize(T& x, const T& new_x){ x = max(x, new_x); }

pair<int, int> check(pair<int, int> res, const vector<int>& S, int extra = 0){
    res.second |= extra;

    for(int x: S){
        res.first = max(res.first, res.second ^ x);
    }
    return res;
}

pair<int, int> dfs(int b, vector<int> S){
    if(S.empty()) return {INT_MAX, 0};
    if(b < 0) return {0, S.back()};

    vector<int> B[2];
    for(int x: S){
        B[x >> b & 1].push_back(x & ~(1 << b));
    }

    pair<int, int> masks[2];
    masks[0] = dfs(b - 1, B[0]);
    masks[1] = dfs(b - 1, B[1]);

    pair<int, int> res = min({
                             check(masks[0], S),
                             check(masks[0], S, 1 << b),
                             check(masks[1], S),
                             check(masks[1], S, 1 << b)
                             });
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << dfs(30, a).first << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
