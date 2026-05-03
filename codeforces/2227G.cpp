/******************************************************************************
Link: https://codeforces.com/contest/2227/problem/G
Code: 2227G
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-01-22.27.18
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

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

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1), pre(n + 1);
    vector<int> temp = {0};
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + (i % 2 == 1 ? a[i] : -a[i]);

        temp.push_back(pre[i]);
    }
    sort(begin(temp), end(temp));
    for(int i = 0; i <= n; ++i)
        pre[i] = lower_bound(begin(temp), end(temp), pre[i]) - begin(temp) + 1;

    vector<FenwickTree> fwt(2, FenwickTree(n + 1));
    fwt[0].update(pre[0], 1);

    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(i & 1) res += fwt[0].get(pre[i] - 1);
        else res += fwt[1].get(pre[i] + 1, n + 1);

        fwt[i & 1].update(pre[i], 1);
    }

    cout << res << "\n";
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
