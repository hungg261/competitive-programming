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

    int get(int l, int r){ if(l > r) return 0; return get(r) - get(l - 1); }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    FenwickTree fwt(n);
    vector<int> already(n + 1, 0);
    vector<int> preLarger(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        preLarger[i] = fwt.get(arr[i], n);

        already[i] = already[i - 1] + (preLarger[i] == 0);
        fwt.update(arr[i], 1);
    }

    FenwickTree cnt1(n);

    int resCnt = -1, resVal = -1;
    for(int i = n; i >= 1; --i){
        int candidate = already[n] - (already[i] - already[i - 1]) + cnt1.get(arr[i]);
        if(candidate > resCnt){
            resVal = arr[i];
            resCnt = candidate;
        }
        else if(candidate == resCnt){
            resVal = min(resVal, arr[i]);
        }

        if(preLarger[i] == 1){
            cnt1.update(arr[i], 1);
        }
    }

    cout << resVal << '\n';

    return 0;
}
