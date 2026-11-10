/******************************************************************************
Link: https://codeforces.com/contest/15/problem/D
Code: 15D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-10-09.58.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;
long long pre[MAX + 5][MAX + 5];

struct ST_Node{
    int mn;

    ST_Node() = default;
    ST_Node(int val): mn(val){}

    ST_Node operator + (const ST_Node &other) const {
        return {min(mn, other.mn)};
    }
};

template<typename Node> struct SegmentTree2D{
    int n, m;
    vector<vector<Node>> nodes;

    SegmentTree2D(int _n, int _m): n(_n), m(_m){
        nodes.resize(n * 4 + 5, vector<Node>(m * 4 + 5));
    }

    void build(){
        build_x(1, 1, n);
    }

    void update(int x, int y, Node val){
        update_x(1, 1, n, x, y, val);
    }

    Node get(int x1, int y1, int x2, int y2) const {
        return get_x(1, 1, n, x1, x2, y1, y2);
    }

private:
    void build_y(int idx, int lx, int rx, int idy, int ly, int ry){
        if(ly == ry){
            if(lx == rx) nodes[idx][idy] = pre[lx][ly];
            else nodes[idx][idy] = nodes[idx << 1][idy] + nodes[idx << 1 | 1][idy];
            return;
        }

        int mid = (ly + ry) >> 1;
        build_y(idx, lx, rx, idy << 1, ly, mid);
        build_y(idx, lx, rx, idy << 1 | 1, mid + 1, ry);

        nodes[idx][idy] = nodes[idx][idy << 1] + nodes[idx][idy << 1 | 1];
    }

    void build_x(int idx, int lx, int rx){
        if(lx != rx){
            int mid = (lx + rx) >> 1;
            build_x(idx << 1, lx, mid);
            build_x(idx << 1 | 1, mid + 1, rx);
        }

        build_y(idx, lx, rx, 1, 1, m);
    }

    void update_y(int idx, int lx, int rx, int idy, int ly, int ry, int u, const Node &val){
        if(ly == ry){
            if(lx == rx){
                nodes[idx][idy] = val;
            }
            else{
                nodes[idx][idy] = nodes[idx << 1][idy] + nodes[idx << 1 | 1][idy];
            }
            return;
        }

        int mid = (ly + ry) >> 1;
        if(u <= mid) update_y(idx, lx, rx, idy << 1, ly, mid, u, val);
        else update_y(idx, lx, rx, idy << 1 | 1, mid + 1, ry, u, val);

        nodes[idx][idy] = nodes[idx][idy << 1] + nodes[idx][idy << 1 | 1];
    }

    void update_x(int idx, int lx, int rx, int x, int y, const Node &val){
        if(lx != rx){
            int mid = (lx + rx) >> 1;
            if(x <= mid) update_x(idx << 1, lx, mid, x, y, val);
            else update_x(idx << 1 | 1, mid + 1, rx, x, y, val);
        }

        update_y(idx, lx, rx, 1, 1, m, y, val);
    }

    Node get_y(int idx, int lx, int rx, int idy, int ly, int ry, int u, int v) const {
        if(u <= ly && ry <= v) return nodes[idx][idy];

        int mid = (ly + ry) >> 1;
        bool oL = u <= mid, oR = mid + 1 <= v;

        if(oL && oR)
            return get_y(idx, lx, rx, idy << 1, ly, mid, u, v)
                + get_y(idx, lx, rx, idy << 1 | 1, mid + 1, ry, u, v);
        else if(oL) return get_y(idx, lx, rx, idy << 1, ly, mid, u, v);
        else return get_y(idx, lx, rx, idy << 1 | 1, mid + 1, ry, u, v);
    }

    Node get_x(int idx, int lx, int rx, int x1, int x2, int y1, int y2) const {
        if(x1 <= lx && rx <= x2) return get_y(idx, lx, rx, 1, 1, m, y1, y2);

        int mid = (lx + rx) >> 1;
        bool oL = x1 <= mid, oR = mid + 1 <= x2;

        if(oL && oR)
            return get_x(idx << 1, lx, mid, x1, x2, y1, y2)
                + get_x(idx << 1 | 1, mid + 1, rx, x1, x2, y1, y2);
        else if(oL) return get_x(idx << 1, lx, mid, x1, x2, y1, y2);
        else return get_x(idx << 1 | 1, mid + 1, rx, x1, x2, y1, y2);
    }
};

struct State{
    long long w;
    int x, y;
    bool operator < (const State &other) const {
        if(w != other.w) return w < other.w;
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

int n, m, a, b;

inline long long get(int x1, int y1, int x2, int y2){
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

namespace BIT2D{
    int bit[MAX + 5][MAX + 5];
    void update(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i)
            for(int j = y; j <= m; j += j & -j)
                bit[i][j] += val;
    }
    int query(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                res += bit[i][j];
        return res;
    }
    int get(int x1, int y1, int x2, int y2){
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
}

void solve(const SegmentTree2D<ST_Node> &ST){
    int max_size = (n - a + 1) * (m - b + 1);
    vector<State> states;
    states.reserve(max_size);
    for(int i = 1; i + a - 1 <= n; ++i){
        for(int j = 1; j + b - 1 <= m; ++j){
            int x = i + a - 1, y = j + b - 1;
            states.push_back({get(i, j, x, y) - 1LL * a * b * ST.get(i, j, x, y).mn,
                             i, j});
        }
    }
    sort(begin(states), end(states));

    vector<int> res;
    res.reserve(max_size);

    for(int i = 0; i < (int)states.size(); ++i){
        const State &s = states[i];

        int xx = s.x + a - 1, yy = s.y + b - 1;
        if(BIT2D::get(s.x, s.y, xx, yy) > 0) continue;

        BIT2D::update(s.x, s.y, 1);
        BIT2D::update(xx, s.y, 1);
        BIT2D::update(s.x, yy, 1);
        BIT2D::update(xx, yy, 1);

        res.push_back(i);
    }

    cout << res.size() << "\n";
    for(int i: res){
        const State &s = states[i];
        cout << s.x << " " << s.y << " " << s.w << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> a >> b;

    SegmentTree2D<ST_Node> ST(n, m);

    {
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin >> pre[i][j];
            }
        }

        ST.build();

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }

    solve(ST);

    return 0;
}
