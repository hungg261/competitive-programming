/******************************************************************************
Link: https://cses.fi/problemset/task/1742
Code: 1742
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-02-08.30.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct SparseBIT2D {
    int n;
    vector<vector<int>> ys;
    vector<vector<long long>> bit;

    SparseBIT2D(int n) : n(n) {
        ys.resize(n + 1);
        bit.resize(n + 1);
    }

    void fake_update(int x, int y) {
        for (int i = x; i <= n; i += i & -i) {
            ys[i].push_back(y);
        }
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            bit[i].assign(ys[i].size() + 1, 0);
        }
    }

    void update(int x, int y, long long v) {
        for (int i = x; i <= n; i += i & -i) {
            int j = lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin() + 1;
            for (; j < (int)bit[i].size(); j += j & -j) {
                bit[i][j] += v;
            }
        }
    }

    long long query(int x, int y) const {
        long long res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            int j = upper_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
            for (; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    long long rect(int x1, int y1, int x2, int y2) const {
        if(x1 > x2 || y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
        }

        return query(x2, y2)
             - query(x1 - 1, y2)
             - query(x2, y1 - 1)
             + query(x1 - 1, y1 - 1);
    }
};

SparseBIT2D compress_and_build(vector<pair<int,int>>& pts) {
    vector<int> xs, ys;
    for (const pair<int, int>& p: pts){
        int x, y; tie(x, y) = p;
        xs.push_back(x), ys.push_back(y);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    SparseBIT2D bit(xs.size());

    for (const pair<int, int>& p: pts){
        int x, y; tie(x, y) = p;
        x = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
        bit.fake_update(x, y);
    }

    bit.build();
    return bit;
}

pair<int, int> get_delta(char d, int x){
    if(d == 'U') return {0, x};
    else if(d == 'D') return {0, -x};
    else if(d == 'L') return {-x, 0};
    else if(d == 'R') return {x, 0};
    throw "wtf";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> points;
    vector<tuple<int, int, int, int>> queries;

    int cx = 0, cy = 0;
    for(int i = 1; i <= n; ++i){
        char d; int x;
        cin >> d >> x;

        int dx, dy; tie(dx, dy) = get_delta(d, x);
        int nx = cx + dx, ny = cy + dy;

//        cout << cx << ' ' << cy << ' ' << nx << ' ' << ny << '\n';

        points.emplace_back(cx, cy);
        points.emplace_back(nx, ny);
        points.emplace_back(cx + 1, cy + 1);
        points.emplace_back(nx + 1, ny + 1);

        queries.emplace_back(cx, cy, nx, ny);

        cx = nx; cy = ny;
    }

    SparseBIT2D bit1 = compress_and_build(points);
    SparseBIT2D bit2 = compress_and_build(points);
    SparseBIT2D bit3 = compress_and_build(points);
    SparseBIT2D bit4 = compress_and_build(points);

    auto update_rect = [&](int x1, int y1, int x2, int y2, long long v){
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        bit1.update(x1, y1, v);
        bit1.update(x1, y2 + 1, -v);
        bit1.update(x2 + 1, y1, -v);
        bit1.update(x2 + 1, y2 + 1, v);

        bit2.update(x1, y1, v * (x1 - 1));
        bit2.update(x1, y2 + 1, -v * (x1 - 1));
        bit2.update(x2 + 1, y1, -v * x2);
        bit2.update(x2 + 1, y2 + 1, v * x2);

        bit3.update(x1, y1, v * (y1 - 1));
        bit3.update(x1, y2 + 1, -v * y2);
        bit3.update(x2 + 1, y1, -v * (y1 - 1));
        bit3.update(x2 + 1, y2 + 1, v * y2);

        bit4.update(x1, y1, v * (x1 - 1) * (y1 - 1));
        bit4.update(x1, y2 + 1, -v * (x1 - 1) * y2);
        bit4.update(x2 + 1, y1, -v * x2 * (y1 - 1));
        bit4.update(x2 + 1, y2 + 1, v * x2 * y2);
    };

    auto prefix = [&](int x, int y){
        long long s1 = bit1.query(x, y);
        long long s2 = bit2.query(x, y);
        long long s3 = bit3.query(x, y);
        long long s4 = bit4.query(x, y);

        return s1 * x * y
             - s2 * y
             - s3 * x
             + s4;
    };

    auto query_rect = [&](int x1, int y1, int x2, int y2){
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        return prefix(x2, y2)
             - prefix(x1 - 1, y2)
             - prefix(x2, y1 - 1)
             + prefix(x1 - 1, y1 - 1);
    };

    int res = 0;
    for(const auto& qr: queries){
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = qr;

        if(query_rect(x1, y1, x2, y2) > 0){
//            res +=
            break;
        }


    }

    return 0;
}
