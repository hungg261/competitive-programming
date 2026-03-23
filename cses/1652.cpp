#include<bits/stdc++.h>
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

struct FenwickTree2D{
    vector<vector<int>> BIT;
    int n, m;

    FenwickTree2D() = default;
    FenwickTree2D(int n, int m, int place = 0){ this->n = n; this->m = m; BIT.resize(n + 1, vector<int>(m + 1, place)); }

    void update(int x, int y, int value){
        for(int i = x; i <= n; i += i & -i){
            for(int j = y; j <= m; j += j & -j){
                BIT[i][j] += value;
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            for(int j = y; j > 0; j -= j & -j){
                res += BIT[i][j];
            }
        }
        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }

    pair<int, int> size(){ return {this->n, this->m}; }

};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;

    FenwickTree2D fwt(n, n);

    for(int i = 1; i <= n; ++i){
        string line; cin >> line;
        for(int j = 1; j <= n; ++j){
            if(line[j - 1] == '*') fwt.update(i, j, 1);
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << fwt.get(x1, y1, x2, y2) << '\n';
    }

    return 0;
}
