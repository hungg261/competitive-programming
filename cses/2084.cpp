/******************************************************************************
Link: https://cses.fi/problemset/task/2084
Code: 2084
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-21-22.57.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, MAXVAL = 1e6;
struct Line{
    int m, c;

    Line(): m(0), c(LLONG_MAX){};
    Line(int _m, int _c): m(_m), c(_c){}

    int eval(int x) const { return m * x + c; }
};

Line nodes[MAXVAL * 4 + 5];
void add_line(int id, int l, int r, Line g){
    int mid = (l + r) >> 1;

    Line& f = nodes[id];
    if(g.eval(mid) < f.eval(mid)) swap(f, g);

    if(l == r) return;
    if(g.eval(l) < f.eval(l)) add_line(id << 1, l, mid, g);
    else if(g.eval(r) < f.eval(r)) add_line(id << 1 | 1, mid + 1, r, g);
}

int get(int id, int l, int r, int x){
    int cur = nodes[id].eval(x);
    if(l == r) return cur;

    int mid = (l + r) >> 1;
    if(x <= mid) return min(cur, get(id << 1, l, mid, x));
    else return min(cur, get(id << 1 | 1, mid + 1, r, x));
}

int n, x;
int s[MAXN + 5], f[MAXN + 5];

int dp[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int i = 1; i <= n; ++i) cin >> f[i];
    f[0] = x;

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    add_line(1, 1, MAXVAL, Line(f[0], dp[0]));

    for(int i = 1; i <= n; ++i){
        dp[i] = get(1, 1, MAXVAL, s[i]);
        add_line(1, 1, MAXVAL, Line(f[i], dp[i]));
    }

    cout << dp[n] << "\n";

    return 0;
}
