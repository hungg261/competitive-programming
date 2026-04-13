/******************************************************************************
Link: https://cses.fi/problemset/task/3223
Code: 3223
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-12-11.55.43
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1), temp(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(begin(temp) + 1, end(temp));

    FenwickTree fwt(n + 1);
    long long invcnt = 0;
    for(int i = 1; i <= n; ++i){
        arr[i] = lower_bound(begin(temp) + 1, end(temp), arr[i]) - begin(temp);

        if(i > k){
            invcnt -= fwt.get(arr[i - k] - 1);
            fwt.update(arr[i - k], -1);
        }

        invcnt += fwt.get(arr[i] + 1, n + 1);
        fwt.update(arr[i], 1);

        if(i >= k) cout << invcnt << " ";
    }


    return 0;
}
