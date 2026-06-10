/******************************************************************************
Link: https://codeforces.com/contest/1288/problem/D
Code: 1288D
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-12-15.26.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> values;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            values.push_back(a[i][j]);
        }
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            a[i][j] = lower_bound(begin(values), end(values), a[i][j]) - begin(values);
        }
    }

    auto check = [&](int mid) -> pair<int, int> {
        vector<int> masks(1 << m, -1);
        for(int i = 0; i < n; ++i){
            int mask = 0;
            for(int j = 0; j < m; ++j){
                if(a[i][j] <= mid) mask |= 1 << j;
            }
            masks[mask] = i;
        }

        for(int m1 = 0; m1 < (1 << m); ++m1){
            for(int m2 = m1; m2 < (1 << m); ++m2){
                if(masks[m1] != -1 && masks[m2] != -1 && (m1 & m2) == 0)
                    return {masks[m1] + 1, masks[m2] + 1};
            }
        }
        return {-1, -1};
    };

    int l = -1, r = (int)values.size() - 1, res = -2;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid).first != -1){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    int i, j; tie(i, j) = check(res);
    cout << i << " " << j << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
