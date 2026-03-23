#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree{
    vector<int> BIT;
    int n;

    FenwickTree() = default;
    FenwickTree(int sz, int place = 0){ this->n = sz; BIT.resize(sz + 1, place); }

    void update(int idx, int value){
        while(idx <= n){
            BIT[idx] += value;
            idx += idx & (-idx);
        }
    }

    int get(int idx){
        int res = 0;
        while(idx > 0){
            res += BIT[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    int get(int l, int r){
        return get(r) - get(l - 1);
    }

    int size(){ return this->n; }
};

struct Range{
    int l, r, idx;

    bool operator < (const Range& other) const{
        if(this->l == other.l) return this->r > other.r;
        return this->l < other.l;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> values;
    vector<Range> arr(n + 1);

    for(int i = 1; i <= n; ++i){
        int l, r; cin >> l >> r;
        arr[i] = {l, r, i};

        values.push_back(l);
        values.push_back(r);
    }
    sort(begin(values), end(values));
    sort(begin(arr) + 1, end(arr));

    FenwickTree fwt_left(n * 2 + 5), fwt_right(n * 2 + 5);
    vector<int> res1(n + 1), res2(n + 1);

    for(int i = 1; i <= n; ++i){
        arr[i].l = lower_bound(begin(values), end(values), arr[i].l) - begin(values) + 1;
        arr[i].r = lower_bound(begin(values), end(values), arr[i].r) - begin(values) + 1;
        fwt_right.update(arr[i].r, 1);
    }

    for(int i = 1; i <= n; ++i){
        int cnt1 = fwt_left.get(arr[i].r, fwt_left.size());
        res2[arr[i].idx] = cnt1;

        fwt_left.update(arr[i].r, 1);
        fwt_right.update(arr[i].r, -1);

        int cnt2 = fwt_right.get(arr[i].r);
        res1[arr[i].idx] = cnt2;
    }

    for(int i = 1; i <= n; ++i){
        cout << res1[i] << ' ';
    } cout << '\n';
    for(int i = 1; i <= n; ++i){
        cout << res2[i] << ' ';
    } cout << '\n';

    return 0;
}
