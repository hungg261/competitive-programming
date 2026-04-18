/******************************************************************************
Link: https://cses.fi/problemset/task/3428
Code: 3428
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-18-11.20.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

struct Line{
    int m, c;

    Line(): m(0), c(-1){}
    Line(int _m, int _c): m(_m), c(_c){}
    Line(int x1, int y1, int x2, int y2){
        m = (y2 - y1) / (x2 - x1);
        c = y1 - m * x1;
    }

    int eval(int x) const { return m * x + c; }
};

Line nodes[MAXN * 4 + 5];

void add_line(int id, int l, int r, Line g){
    int mid = (l + r) >> 1;

    Line f = nodes[id];
    if(g.eval(mid) > f.eval(mid)) swap(f, g);

    nodes[id] = f;

    if(l == r) return;
    if(g.eval(l) > f.eval(l)) add_line(id << 1, l, mid, g);
    else if(g.eval(r) > f.eval(r)) add_line(id << 1 | 1, mid + 1, r, g);
}

void add_segment(int id, int l, int r, int x1, int x2, Line g){
    if(r < x1 || x2 < l) return;
    if(x1 <= l && r <= x2){
        add_line(id, l, r, g);
        return;
    }

    int mid = (l + r) >> 1;
    add_segment(id << 1, l, mid, x1, x2, g);
    add_segment(id << 1 | 1, mid + 1, r, x1, x2, g);
}

int get_max(int id, int l, int r, int x){
    int cur = nodes[id].eval(x);
    if(l == r) return cur;

    int mid = (l + r) >> 1;
    if(x <= mid) return max(cur, get_max(id << 1, l, mid, x));
    else return max(cur, get_max(id << 1 | 1, mid + 1, r, x));
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        add_segment(1, 0, m, x1, x2, Line(x1, y1, x2, y2));
    }

    for(int x = 0; x <= m; ++x){
        cout << get_max(1, 0, m, x) << " ";
    }

    return 0;
}
