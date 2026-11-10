/******************************************************************************
Link: https://codeforces.com/contest/677/problem/D
Code: 677D
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-10-20.30.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

template<typename Node> struct SegmentTree2D{
    int n, m;
    vector<vector<Node>> nodes;

    SegmentTree2D(int _n, int _m): n(_n), m(_m){
        nodes.resize(n * 4 + 5, vector<Node>(m * 4 + 5));
    }

    void build(const vector<vector<Node>> &arr){
        build_x(1, 1, n, arr);
    }

    void update(int x, int y, Node val){
        update_x(1, 1, n, x, y, val);
    }

    Node get(int x1, int y1, int x2, int y2) const {
        return get_x(1, 1, n, x1, x2, y1, y2);
    }

private:
    void build_y(int idx, int lx, int rx, int idy, int ly, int ry, const vector<vector<Node>> &arr){
        if(ly == ry){
            if(lx == rx) nodes[idx][idy] = arr[lx][ly];
            else nodes[idx][idy] = nodes[idx << 1][idy] + nodes[idx << 1 | 1][idy];
            return;
        }

        int mid = (ly + ry) >> 1;
        build_y(idx, lx, rx, idy << 1, ly, mid, arr);
        build_y(idx, lx, rx, idy << 1 | 1, mid + 1, ry, arr);

        nodes[idx][idy] = nodes[idx][idy << 1] + nodes[idx][idy << 1 | 1];
    }

    void build_x(int idx, int lx, int rx, const vector<vector<Node>> &arr){
        if(lx != rx){
            int mid = (lx + rx) >> 1;
            build_x(idx << 1, lx, mid, arr);
            build_x(idx << 1 | 1, mid + 1, rx, arr);
        }

        build_y(idx, lx, rx, 1, 1, m, arr);
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    const int INF = INT_MAX / 2;

    vector<vector<pair<int, int>>> pos(p + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int cur; cin >> cur;
            pos[cur].push_back({i, j});
        }
    }

    struct Node{
        int val;

        Node(): val(INF){}
        Node(int _val): val(_val){}

        Node operator + (const Node &other) const {
            return {min(val, other.val)};
        }
    };
    SegmentTree2D<Node> ST1(n, m), ST2(n, m), ST3(n, m), ST4(n, m);


    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(const pair<int, int> &e: pos[1]){
        int x, y; tie(x, y) = e;
        dp[x][y] = (x - 1) + (y - 1);
    }

    for(int c = 2; c <= p; ++c){
        for(const pair<int, int> &e: pos[c - 1]){
            int i, j; tie(i, j) = e;
            ST1.update(i, j, dp[i][j] - i - j);
            ST2.update(i, j, dp[i][j] - i + j);
            ST3.update(i, j, dp[i][j] + i - j);
            ST4.update(i, j, dp[i][j] + i + j);
        }

        for(const pair<int, int> &e: pos[c]){
            int x, y; tie(x, y) = e;
            int ans = INF;
            ans = min(ans, ST1.get(1, 1, x, y).val + x + y);
            ans = min(ans, ST2.get(1, y + 1, x, m).val + x - y);
            ans = min(ans, ST3.get(x + 1, 1, n, y).val - x + y);
            ans = min(ans, ST4.get(x + 1, y + 1, n, m).val - x - y);
            dp[x][y] = ans;
        }

        for(const pair<int, int> &e: pos[c - 1]){
            int i, j; tie(i, j) = e;
            ST1.update(i, j, INF);
            ST2.update(i, j, INF);
            ST3.update(i, j, INF);
            ST4.update(i, j, INF);
        }
    }

    int x, y; tie(x, y) = pos[p].back();
    cout << dp[x][y] << "\n";

    return 0;
}
