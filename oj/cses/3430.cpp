/******************************************************************************
Link: https://cses.fi/problemset/task/3430
Code: 3430
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-18-12.16.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5, MAXVAL = 1e5;

struct Line{
    int m, c;

    Line(): m(0), c(LLONG_MIN){};
    Line(int _m, int _c): m(_m), c(_c){}

    int eval(int x) const { return m * x + c; }
};

Line nodes[MAXN * 4 + 5];

void add_line(int id, int L, int R, Line g){
    int mid = (L + R) >> 1;

    Line& f = nodes[id];
    if(g.eval(mid) > f.eval(mid)) swap(f, g);

    if(g.eval(L) > f.eval(L)) add_line(id << 1, L, mid, g);
    else if(g.eval(R) > f.eval(R)) add_line(id << 1 | 1, mid + 1, R, g);
}

void add_segment(int id, int L, int R, int x1, int x2, Line g){
    if(x2 < L || R < x1) return;
    if(x1 <= L && R <= x2){
        add_line(id, L, R, g);
        return;
    }

    int mid = (L + R) >> 1;
    add_segment(id << 1, L, mid, x1, x2, g);
    add_segment(id << 1 | 1, mid + 1, R, x1, x2, g);
}

int get_max(int id, int L, int R, int x){
    int cur = nodes[id].eval(x);
    if(L == R) return cur;

    int mid = (L + R) >> 1;
    if(x <= mid) return max(cur, get_max(id << 1, L, mid, x));
    else return max(cur, get_max(id << 1 | 1, mid + 1, R, x));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int a, b, l, r;
            cin >> a >> b >> l >> r;

            add_segment(1, 0, MAXVAL, l, r, Line(a, b));
        }
        else{
            int x;
            cin >> x;

            int res = get_max(1, 0, MAXVAL, x);
            if(res == LLONG_MIN) cout << "NO\n";
            else cout << res << "\n";
        }
    }

    return 0;
}
