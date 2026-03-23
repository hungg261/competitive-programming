/******************************************************************************
Link: https://codeforces.com/problemset/problem/1773/E
Code: 1773E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-22.18.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> values;
    vector<vector<int>> arr(n);

    for(int i = 0; i < n; ++i){
        int k; cin >> k;

        arr[i].resize(k);
        for(int j = 0; j < k; ++j){
            cin >> arr[i][j];
            values.push_back(arr[i][j]);
        }
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    for(int i = 0; i < n; ++i){
        for(int& ele: arr[i]){
            ele = lower_bound(begin(values), end(values), ele) - begin(values);
        }
    }

    int s = 0, c = 0;
    for(int i = 0; i < n; ++i){
        int k = arr[i].size();
        for(int j = 1; j < k; ++j){
            if(arr[i][j - 1] + 1 != arr[i][j]){
                ++s;
            }
        }
    }

    c = n + s - 1;

    cout << s << ' ' << c << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
