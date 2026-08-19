/******************************************************************************
Link: https://cses.fi/problemset/task/3429
Code: 3429
Time (YYYY-MM-DD-hh.mm.ss): 2026-08-18-09.07.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Line{
    int m, c;

    Line(int _m = 0, int _c = LLONG_MIN): m(_m), c(_c){}

    int eval(int x){
        return m * x + c;
    }

    bool operator < (const Line& other) const {
        return m < other.m || (m < other.m && c < other.c);
    }

    friend istream& operator >> (istream& is, Line& l){
        return is >> l.m >> l.c;
    }
    friend ostream& operator << (ostream& os, Line& l){
        return os << l.m << l.c;
    }
};

const int MAXN = 2e5, MAXVAL = 1e5;
Line nodes[MAXVAL * 4 + 5];

void add_line(Line f, int id = 1, int l = 0, int r = MAXVAL){
    int mid = (l + r) >> 1;
    Line& g = nodes[id];
    if(f.eval(mid) > g.eval(mid)) swap(g, f);

    if(l == r) return;

    if(f.eval(l) > g.eval(l)) add_line(f, id << 1, l, mid);
    else add_line(f, id << 1 | 1, mid + 1, r);
}

void add_segment(Line f, int u, int v, int id = 1, int l = 0, int r = MAXVAL){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        add_line(f, id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    add_segment(f, u, v, id << 1, l, mid);
    add_segment(f, u, v, id << 1 | 1, mid + 1, r);
}

int get(int x, int id = 1, int l = 0, int r = MAXVAL){
    int cur = nodes[id].eval(x);
    if(l == r) return cur;

    int mid = (l + r) >> 1;
    if(x <= mid) cur = max(cur, get(x, id << 1, l, mid));
    else cur = max(cur, get(x, id << 1 | 1, mid + 1, r));
    return cur;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b;
            cin >> a >> b;

            add_line(Line(a, b));
        }
        else if(type == 2){
            int x;
            cin >> x;

            cout << get(x) << "\n";
        }
    }

    return 0;
}
