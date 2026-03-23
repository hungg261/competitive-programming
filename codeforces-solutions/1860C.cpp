/******************************************************************************
Link: https://codeforces.com/problemset/problem/1860/C
Code: 1860C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-07-23.55.12
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

    vector<int> arr(n + 1), pos(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    FenwickTree fwt(n);
    int minIdx = n + 1;
    int ans = 0;
    for(int ele = 1; ele <= n; ++ele){
        int g = fwt.get(pos[ele]);
        if(pos[ele] < minIdx && g >= 1){
            minIdx = pos[ele];
            ++ans;
        }

        fwt.update(pos[ele], 1);
    }

    cout << ans << '\n';
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
