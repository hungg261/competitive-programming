/******************************************************************************
Link: https://codeforces.com/contest/2101/problem/B
Code: 2101B
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-06-17.18.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

int inv(const deque<int>& arr, const int& MAX){
    FenwickTree fwt(MAX);
    int res = 0;
    for(int i = (int)arr.size() - 1; i >= 0; --i){
        res += fwt.get(arr[i]);
        fwt.update(arr[i], 1);
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    array<deque<int>, 2> arr;
    for(int i = 0; i < n; ++i){
        int cur; cin >> cur;
        arr[i & 1].push_back(cur);
    }

    bool c = (inv(arr[0], n) & 1) ^ (inv(arr[1], n) & 1);
    sort(begin(arr[0]), end(arr[0]));
    sort(begin(arr[1]), end(arr[1]));

    vector<int> res(n);

    for(int i = 0; i < n; ++i){
        res[i] = arr[i & 1].front();
        arr[i & 1].pop_front();
    }

    bool new_c = (inv(arr[0], n) & 1) ^ (inv(arr[1], n) & 1);
    if(c != new_c) swap(res[n - 3], res[n - 1]);

    for(int ele: res) cout << ele << " "; cout << "\n";
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
