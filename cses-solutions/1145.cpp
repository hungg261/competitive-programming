#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    vector<int> BIT;
    int n;

    FenwickTree() = default;
    FenwickTree(int sz, int place = 0){ this->n = sz; BIT.resize(sz + 1, place); }

    void update(int idx, int value){
        while(idx <= n){
            BIT[idx] = max(BIT[idx], value);
            idx += idx & (-idx);
        }
    }

    int get(int idx){
        int res = 0;
        while(idx > 0){
            res = max(res, BIT[idx]);
            idx -= idx & (-idx);
        }
        return res;
    }

    int size(){ return this->n; }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(begin(arr) + 1, end(arr), [](pair<int, int>& u, pair<int, int>& v){ return u.first < v.first || (u.first == v.first && u.second > v.second); });

    FenwickTree fwt(n);
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        int idx = arr[i].second;
        dp[idx] = fwt.get(idx - 1) + 1;
        fwt.update(idx, dp[idx]);
    }

    int ans = *max_element(begin(dp) + 1, end(dp));
    cout << ans << '\n';

    return 0;
}
