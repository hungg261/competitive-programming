/******************************************************************************
Link: https://judge.yosupo.jp/problem/rectangle_sum
Code: rectangle_sum
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-15-13.27.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

struct FenwickTree2D{
    int n, m;
    vector<vector<int>> ys;
    vector<vector<int>> bit;

    FenwickTree2D(int _n, int _m): n(_n), m(_m){
        ys.resize(n + 1);
    }

    void fake_update(int x, int y){
        for(int i = x; i <= n; i += i & -i){
            ys[i].push_back(y);
        }
    }

    void build(){
        bit.resize(n + 1);
        for(int x = 1; x <= n; ++x){
            ys[x].push_back(0);
            sort(begin(ys[x]), end(ys[x]));
            ys[x].erase(unique(begin(ys[x]), end(ys[x])), end(ys[x]));
            bit[x].resize(ys.size(), 0);
        }
    }

    void update(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i){
            int j = lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);
            for(; j < (int)bit[i].size(); j += j & -j){
                bit[i][j] += val;
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i >= 1; i -= i & -i){
            int j = upper_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]) - 1;
            for(; j >= 1; j -= j & -j){
                res += bit[i][j];
            }
        }

        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

int n, q;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    FenwickTree2D()
    for(int i = 1; i <= n; ++i){
        int x, y, w;
        cin >> x >> y >> w;


    }

    return 0;
}
