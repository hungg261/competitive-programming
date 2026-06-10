/******************************************************************************
Link: https://vjudge.net/contest/732386#problem/D
Code: D
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-04-15.59.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct FenwickTree2D{
    vector<vector<int>> nodes;
    vector<vector<int>> BIT;
    int n, m;

    FenwickTree2D() = default;
    FenwickTree2D(int _n, int _m): n(_n), m(_m){ nodes.resize(_n + 1); BIT.resize(_m + 1); }

    void fakeUpdate(int x, int y){
        for(int i = x; i <= n; i += i & -i) nodes[i].push_back(y);
    }

    void fakeQuery(int x, int y){
        for(int i = x; i > 0; i -= i & -i) nodes[i].push_back(y);
    }

    void compress(){
        for(int i = 1; i <= n; ++i){
            nodes[i].push_back(0);
            sort(begin(nodes[i]), end(nodes[i]));
            nodes[i].erase(unique(begin(nodes[i]), end(nodes[i])), end(nodes[i]));

            BIT[i].resize((int) nodes[i].size() + 1, 0);
        }
    }

    void update(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i){
            int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]) + 1;
            for(; j <= (int)nodes[i].size(); j += j & -j){
                BIT[i][j] += val;
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            int j = lower_bound(begin(nodes[i]), end(nodes[i]), y) - begin(nodes[i]) + 1;
            for(; j > 0; j -= j & -j){
                res += BIT[i][j];
            }
        }

        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

struct Query{
    int type;
    int a, b, c, d;

    tuple<int, int> getUpdate() const{
        return make_tuple(a, b);
    }

    tuple<int, int, int, int> getQuery() const{
        return make_tuple(a, b, c, d);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;

    FenwickTree2D fwt(n, n);

    vector<vector<bool>> forest(n + 1, vector<bool>(n + 1, false));
    for(int i = 1; i <= n; ++i){
        string line; cin >> line;
        for(int j = 1; j <= n; ++j){
            if(line[j - 1] == '*'){
                forest[i][j] = true;
                fwt.fakeUpdate(i, j);
            }
        }
    }

    vector<Query> queries;
    for(int i = 1; i <= q; ++i){
        int type; cin >> type;

        if(type == 1){
            int x, y;
            cin >> x >> y;

            fwt.fakeUpdate(x, y);
            queries.push_back({type, x, y, -1, -1});
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            fwt.fakeQuery(x1 - 1, y1 - 1);
            fwt.fakeQuery(x1 - 1, y2);
            fwt.fakeQuery(x2, y1 - 1);
            fwt.fakeQuery(x2, y2);
            queries.push_back({type, x1, y1, x2, y2});
        }
    }

    fwt.compress();

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(forest[i][j]) fwt.update(i, j, 1);
        }
    }

    for(const Query& qr: queries){
        if(qr.type == 1){
            int x, y;
            tie(x, y) = qr.getUpdate();

            fwt.update(x, y, forest[x][y] ? -1 : 1);
            forest[x][y] = 1 - forest[x][y];
        }
        else{
            int x1, y1, x2, y2;
            tie(x1, y1, x2, y2) = qr.getQuery();

            cout << fwt.get(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}