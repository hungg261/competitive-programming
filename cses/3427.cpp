/******************************************************************************
Link: https://cses.fi/problemset/task/3427
Code: 3427
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-16-09.05.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Line{
    int m, c;
    int idx;

    Line() = default;
    Line(int _m, int _c): m(_m), c(_c){}
    Line(int x1, int y1, int x2, int y2){
        m = (y2 - y1) / (x2 - x1);
        c = - m * x1 + y1;
    }

    int f(int x) const { return m * x + c; }
    int slope() const { return m; }

    pair<int, int> intersect(const Line& other) const {
        assert(m != other.m);

        int x = (c - other.c) / (other.m - m);
        int y = f(x);

        return {x, y};
    }

    bool operator == (const Line& other) const { return slope() == other.slope(); }
    bool operator < (const Line& other) const {
        return m < other.m || (m == other.m && c < other.c);
    }
    bool operator > (const Line& other) const {
        return m > other.m || (m == other.m && c > other.c);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Line> l(n);
    for(int i = 0; i < n; ++i){
        int y1, y2;
        cin >> y1 >> y2;

        l[i] = Line(0, y1, m, y2);
        l[i].idx = i;
    }
    sort(begin(l), end(l));

    vector<int> sta;
    int sz = 0;
    for(int i = 0; i < n; ++i){
        if(sz > 0 && l[sta[sz - 1]].m == l[i].m) sta.pop_back(), --sz;
        while(sz >= 2){
            const Line& last1 = l[sta[sz - 1]];
            const Line& last2 = l[sta[sz - 2]];
            const Line& cur = l[i];

            if(last2.intersect(last1) >= last1.intersect(cur)){
                sta.pop_back();
                --sz;
            }
            else break;
        }

        sta.push_back(i);
        ++sz;
    }

    int i = 0;
    for(int x = 0; x <= m; ++x){
        while(i + 1 < sz && l[sta[i]].f(x) <= l[sta[i + 1]].f(x))
            ++i;

        cout << l[sta[i]].f(x) << " ";
    }

    return 0;
}
