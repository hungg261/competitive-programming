/******************************************************************************
Link: https://codeforces.com/problemset/problem/1956/C
Code: 1956C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-18.11.11
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, vector<int>>> res;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    vector<int> r(n);
    iota(begin(r), end(r), 1);

    for(int i = n; i >= 1; --i){
        for(int j = 1; j <= n; ++j){
            arr[i - 1][j - 1] = arr[j - 1][i - 1] = j;
        }

        res.emplace_back(1, i, r);
        res.emplace_back(2, i, r);
    }

    int sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            sum += arr[i][j];

    cout << sum << ' ' << res.size() << '\n';
    for(const auto& qr: res){
        cout << get<0>(qr) << ' ' << get<1>(qr) << ' ';
        for(int ele: get<2>(qr)){
            cout << ele << ' ';
        }
        cout << '\n';
    }
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
