/******************************************************************************
Link: https://codeforces.com/contest/2171/problem/D
Code: 2171D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-08-00.22.13
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

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    FenwickTree fwt(n);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        fwt.update(arr[i], 1);
    }

    for(int i = n; i >= 1; --i){
        if(fwt.get(arr[i], arr[i]) == 0) continue;
        if(fwt.get(arr[i] - 1) == 0){
            cout << "No\n";
            return;
        }

        fwt.update(arr[i], -1);
    }

    cout << "Yes\n";
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
