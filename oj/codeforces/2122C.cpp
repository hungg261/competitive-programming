/******************************************************************************
Link: https://codeforces.com/contest/2122/problem/C
Code: 2122C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-02-21.20.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    int idx;

    void input(int i){
        idx = i;
        cin >> x >> y;
    }

    bool operator == (const Point& other){
        return idx == other.idx;
    }

    static bool cmpX(Point& a, Point& b){
        return a.x < b.x;
    }
    static bool cmpY(Point& a, Point& b){
        return a.y < b.y;
    }
};

vector<Point> merges(const vector<Point>& a, const vector<Point>& b){
    vector<Point> res;
    set<int> mark;

    for(const auto& p: a) mark.insert(p.idx);
    for(const auto& p: b) if(mark.count(p.idx)) res.push_back(p);

    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<Point> pts(n);
    for(int i = 0; i < n; ++i){
        pts[i].input(i);
    }

    sort(begin(pts), end(pts), Point::cmpX);
    vector<Point> Lx(begin(pts), begin(pts) + n / 2), Rx(begin(pts) + n / 2, end(pts));

    sort(begin(pts), end(pts), Point::cmpY);
    vector<Point> Ly(begin(pts), begin(pts) + n / 2), Ry(begin(pts) + n / 2, end(pts));

    vector<Point> U, V;
    U = merges(Lx, Ly);
    V = merges(Rx, Ry);

    vector<pair<int, int>> res;
    for(int i = 0; i < (int)U.size(); ++i){
        int u, v;
        tie(u, v) = {U[i].idx, V[i].idx};

        if(u > v) swap(u, v);
        res.emplace_back(u, v);
    }

    U = merges(Lx, Ry);
    V = merges(Rx, Ly);

    for(int i = 0; i < (int)U.size(); ++i){
        int u, v;
        tie(u, v) = {U[i].idx, V[i].idx};

        if(u > v) swap(u, v);
        res.emplace_back(u, v);
    }

    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));

    for(auto p: res){
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
