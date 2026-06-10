/******************************************************************************
Link: https://codeforces.com/problemset/problem/2148/F
Code: 2148F
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-02-15.19.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e9;
const int MAXK = 2e5;

template<typename T> inline int sz(const T& vec){ return vec.size(); }

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n);
    int maxlen = 0;
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int cur; cin >> cur;
            arr[i].push_back(cur);
        }
        maxlen = max(maxlen, k);
    }

    sort(begin(arr), end(arr), [](auto& x, auto& y){ return x.size() > y.size(); });

    vector<int> best_idx(maxlen);
    vector<int> prv(n, 0);
    for(int j = maxlen - 1; j >= 0; --j){
        vector<int> cur;
        for(int i = 0; i < n; ++i){
            if(j >= sz(arr[i])) break;

            cur.push_back(i);
        }

        auto cmp = [&arr, &prv, &j](int x, auto y) -> bool {
            return arr[x][j] < arr[y][j] || (arr[x][j] == arr[y][j] && prv[x] < prv[y]);
        };

        sort(begin(cur), end(cur), cmp);

        best_idx[j] = cur[0];
        for(int i = 0; i < sz(cur); ++i){
            prv[cur[i]] = i + 1;
        }
    }

    for(int i = 0; i < maxlen; ){
        int idx = best_idx[i];
        for(int j = i; j < sz(arr[idx]); ++j){
            cout << arr[idx][j] << " ";
            ++i;
        }
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
