/******************************************************************************
Link: https://marisaoj.com/problem/363
Code: 363
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-26-21.10.37
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree(int sz): n(sz){
        BIT.resize(n + 1, 0);
    }

    void add(int idx, int val){
        for(int i = idx; i <= n; i += i & -i)
            BIT[i] += val;
    }

    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i & -i)
            res += BIT[i];

        return res;
    }

    int lower_bound(int value){
        int LG = __lg(n);
        int pos = 0, sum = 0;
        for(int b = LG; b >= 0; --b){
            int newPos = pos + (1 << b);

            if(newPos < n && sum + BIT[newPos] < value){
                sum += BIT[newPos];
                pos = newPos;
            }
        }

        return pos + 1;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    FenwickTree fwt(n);
    for(int i = 1; i <= n; ++i) fwt.add(i, 1);

    vector<int> res(n + 1);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;

        int pos = fwt.lower_bound(cur + 1);
        fwt.add(pos, -1);

        res[pos] = i;
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }

    return 0;
}
