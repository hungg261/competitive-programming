#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

struct FenwickTree{
    vector<int> BIT;
    int n;

    FenwickTree() = default;
    FenwickTree(int sz, int place = 0){ this->n = sz; BIT.resize(sz + 1, place); }

    void update(int idx, int value){
        while(idx <= n){
            BIT[idx] = (BIT[idx] + value) % MOD;
            idx += idx & (-idx);
        }
    }

    int get(int idx){
        int res = 0;
        while(idx > 0){
            res = (res + BIT[idx]) % MOD;
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
        dp[idx] = 1 + fwt.get(idx - 1); dp[idx] %= MOD;
        fwt.update(idx, dp[idx]);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
