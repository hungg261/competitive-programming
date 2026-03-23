/******************************************************************************
Link: https://codeforces.com/problemset/problem/2129/A
Code: 2129A
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-30-21.23.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<vector<int>> R(n * 2 + 1);

    for(int i = 0; i < n; ++i){
        cin >> arr[i].first >> arr[i].second;
        R[arr[i].first].push_back(i);
    }

    int last = -1;
    vector<int> res;
    for(int l = 1; l <= n * 2; ++l){
        int furthest = -1, idx = -1;
        for(int i: R[l]){
            int r = arr[i].second - 1;
            if(r > furthest){
                furthest = r;
                idx = i;
            }
        }

        if(furthest > last){
            res.push_back(idx);
            last = furthest;
        }
    }

    sort(begin(res), end(res));
    cout << res.size() << '\n';
    for(int ele: res) cout << ele + 1 << ' '; cout << '\n';
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
