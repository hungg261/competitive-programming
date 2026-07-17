/******************************************************************************
Link: https://oj.uz/problem/view/CEOI18_glo
Code: CEOI18_glo
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-17-09.47.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, d, arr[MAXN + 5];

int LIS(const vector<int>& a){
    if(a.empty()) return 0;
    int sz = a.size();

    vector<int> tail = {a[0]};
    for(int i = 1; i < sz; ++i){
        if(a[i] > tail.back()) tail.push_back(a[i]);
        else *lower_bound(begin(tail), end(tail), a[i]) = a[i];
    }

    return tail.size();
}

namespace Naive{

void solve(){
    vector<int> a(arr + 1, arr + n + 1);
    int res = LIS(a);
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            for(int r = -d; r <= d; ++r){
                for(int k = i; k < j; ++k) a[k] += r;
                res = max(res, LIS(a));
                for(int k = i; k < j; ++k) a[k] -= r;
            }
        }
    }

    cout << res << "\n";
}

}

namespace Brute{

int subsolve(){
    vector<int> a(arr + 1, arr + n + 1);
    int res = LIS(a);
    for(int i = 0; i < n; ++i){
        a[i] -= d;
        cerr << i + 1 << ": " << LIS(a) << endl;
        res = max(res, LIS(a));
    }

    return res;
}

void solve(){
    int res = subsolve();
    cout << res << "\n";
}

}

namespace Solve{

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 5, 0); }

    void update(int idx, int val){
        ++idx;
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] = max(BIT[i], val);
        }
    }

    int get(int idx){
        ++idx;
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res = max(res, BIT[i]);
        }
        return res;
    }
};

int subsolve(){
    vector<int> values;
    for(int i = 1; i <= n; ++i){
        values.push_back(arr[i]);
        values.push_back(arr[i] - d);
    }
    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    auto f = [&](int x){ return lower_bound(begin(values), end(values), x) - begin(values) + 1; };

    vector<int> suf(n + 1);
    int sz = values.size() + 3;

    {
        FenwickTree fwt(sz);
        for(int i = n; i >= 1; --i){
            suf[i] = fwt.get(sz - f(arr[i] - d) - 1) + 1;
            fwt.update(sz - f(arr[i]), fwt.get(sz - f(arr[i]) - 1) + 1);
        }
    }

    int res = 0;
    FenwickTree fwt(sz + 5);
    for(int i = 1; i <= n; ++i){
        int pre = fwt.get(f(arr[i] - d) - 1) + 1;
        fwt.update(f(arr[i] - d), pre);

        res = max(res, pre + suf[i] - 1);
    }

    return res;
}

void solve(){
    int res = subsolve();
    cout << res << "\n";
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    Solve::solve();

    return 0;
}
