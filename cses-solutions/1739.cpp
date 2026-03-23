/******************************************************************************
Link: https://cses.fi/problemset/task/1739
Code: 1739
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-02-23.15.37
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree2D{
    vector<vector<int>> BIT;
    vector<vector<int>> nodes;
    int n, m;

    FenwickTree2D() = default;
    FenwickTree2D(int _n, int _m): n(_n), m(_m){
        BIT.resize(n + 1);
        nodes.resize(n + 1);
    }

    void fakeUpdate(int x, int y){
        for(; x <= m; x += x & -x)
            nodes[x].push_back(y);
    }

    void fakeQuery(int x, int y){
        for(; x > 0; x -= x & -x)
            nodes[x].push_back(y);
    }

    void compress(){
        for(int i = 1; i <= n; ++i){
            nodes[i].push_back(0);
            sort(begin(nodes[i]), end(nodes[i]));
            nodes[i].erase(unique(begin(nodes[i]), end(nodes[i])), end(nodes[i]));
            BIT[i].resize(nodes[i].size(), 0);
        }
    }

    void update(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i){
            for(int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]); j < BIT[i].size(); j += j & -j){
                BIT[i][j] += val;
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i <= n; i += i & -i){
            for(int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]); j <= m; j += j & -j){
                res += BIT[i][j];
            }
        }

        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("1739.INP","r",stdin);
    //freopen("1739.OUT","w",stdout);
    int n, q;
    cin >> n >> q;

    FenwickTree2D fwt2d(n, n);
    vector<string> forest(n);
    for(int i = 0; i < n; ++i){
        cin >> forest[i];
        for(int j = 0; j < n; ++j){
            fwt2d.fakeUpdate(i, j);
        }
    }

    while(q--){
        int
    }

    return 0;
}
