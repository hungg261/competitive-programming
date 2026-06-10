/******************************************************************************
Link: https://cses.fi/problemset/task/3227
Code: 3227
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-24-18.40.41
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
struct LichaoTree{
    struct Line{
        int m, c;

        Line(): m(0), c(LLONG_MIN){};
        Line(int _m, int _c): m(_m), c(_c){}

        int eval(int x) const { return m * x + c; }

        friend istream& operator >> (istream& is, Line& L){ return is >> L.m >> L.c; }
        friend ostream& operator << (ostream& os, const Line& L){
            return os << "y = " << L.m << "x + " << L.c;
        }
    };

    int n;
    vector<Line> nodes;

    LichaoTree(int _n): n(_n){
        nodes.resize(n * 4 + 1);
    }

    void add_line(int id, int l, int r, Line g){
        int mid = (l + r) >> 1;
        Line& f = nodes[id];

        if(g.eval(mid) > f.eval(mid)) swap(f, g);

        if(l == r) return;
        if(g.eval(l) > f.eval(l)) add_line(id << 1, l, mid, g);
        else if(g.eval(r) > f.eval(r)) add_line(id << 1 | 1, mid + 1, r, g);
    }

    void add_segment(int id, int l, int r, int u, int v, Line g){
        if(v < l || r < u) return;
        if(u <= l && r <= v){
            add_line(id, l, r, g);
            return;
        }

        int mid = (l + r) >> 1;
        add_segment(id << 1, l, mid, u, v, g);
        add_segment(id << 1 | 1, mid + 1, r, u, v, g);
    }

    int get(int id, int l, int r, int x) const {
        int cur = nodes[id].eval(x);
        if(l == r) return cur;

        int mid = (l + r) >> 1;
        if(x <= mid) return max(cur, get(id << 1, l, mid, x));
        else return max(cur, get(id << 1 | 1, mid + 1, r, x));
    }

    int get(int id, int l, int r, int u, int v) const {
        return max(get(id, l, r, u), get(id, l, r, v));
    }

    void add_line(Line g){ add_line(1, 1, n, g); }
    void add_segment(int l, int r, Line g){ add_segment(1, 1, n, l, r, g); }
    int get(int x) const { return get(1, 1, n, x); }
    int get(int l, int r) const { return get(1, 1, n, l, r); }
};
typedef LichaoTree::Line Line;

int n, k, x[MAXN + 5];
int L[MAXN + 5], R[MAXN + 5];

void compute(){
    vector<int> sta;
    for(int i = 1; i <= n; ++i){
        while(!sta.empty() && x[sta.back()] >= x[i]) sta.pop_back();

        L[i] = sta.empty() ? 0 : sta.back();
        sta.push_back(i);
    }

    sta.clear();
    for(int i = n; i >= 1; --i){
        while(!sta.empty() && x[sta.back()] >= x[i]) sta.pop_back();

        R[i] = sta.empty() ? n + 1 : sta.back();
        sta.push_back(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> x[i];

    compute();

    LichaoTree LCT(n + 1);
    LCT.add_line(Line(0, 0));

    for(int i = 1; i <= n; ++i){
        int S1 = min(L[i] + k, R[i] - 1), S2 = max(L[i] + k, R[i] - 1);
        LCT.add_segment(INT_MIN, S1, Line(x[i], -x[i] * L[i]));
        LCT.add_segment(S2, INT_MAX, Line(-x[i], x[i] * (R[i] + k - 1)));
        LCT.add_segment(S1, S2, Line(0, x[i] * min(k, R[i] - L[i] - 1)));
    }

    for(int i = k; i <= n; ++i){
        cout << LCT.get(i) << " ";
    }
    cout << "\n";

    return 0;
}
