/******************************************************************************
Link: https://marisaoj.com/problem/390
Code: 390
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-26-17.58.49
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
        ++idx;
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        ++idx;
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

struct Prefix{
    int sum;
    int idx;

    bool operator < (const Prefix& other) const{
        return sum < other.sum || (sum == other.sum && idx < other.idx);
    }

    operator int() const{ return sum; }
    &operator int() { return sum; }
};

const int MAXN = 1e5;
int n, k;
Prefix pre[MAXN + 5];

int get(int mid){
    FenwickTree mark(n + 1);
    int pos = 0;

    int cnt = 0;
    for(int j = 0; j <= n; ++j){
        while(pos <= n && pre[pos].sum <= pre[j].sum - mid){
            mark.update(pre[pos].idx, 1);
            ++pos;
        }

        cnt += mark.get(pre[j].idx - 1);
    }

    return cnt;
}

int solve(){
    int l = -1e14, r = 1e14, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(get(mid) >= k){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    pre[0].sum = 0; pre[0].idx = 0;
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        pre[i].sum = pre[i - 1].sum + cur;
        pre[i].idx = i;
    }
    sort(pre, pre + n + 1);

    int res = solve();
    cout << res << '\n';

    return 0;
}
