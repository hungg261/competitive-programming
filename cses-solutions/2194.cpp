/******************************************************************************
Link: https://cses.fi/problemset/task/2194
Code: 2194
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-16.47.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
const int INF = 9e18;
struct Point{
    int x, y;

    Point(){}
    Point(int _x, int _y): x(_x), y(_y){}

    void input(){
        cin >> x >> y;
    }

    bool operator < (const Point& other) const{
        return this->x < other.x;
    }

    int sqdist(const Point& other) const{
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
} P[MAXN + 5];
int n;

struct cmp{
    bool operator() (const Point& a, const Point& b) const{
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    }
};

void solve(){
    set<Point, cmp> S;
    int res = INF;

    int l = 1;
    for(int i = 1; i <= n; ++i){
        int d = sqrt(res);

        while(l <= n && P[l].x + d < P[i].x)
            S.erase(P[l++]);

        auto low = S.lower_bound(Point(-INF, P[i].y - d));
        for(auto it = low; it != S.end() && it->y <= P[i].y + d; ++it){
            res = min(res, P[i].sqdist(*it));
        }

        S.insert(P[i]);
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2194.INP","r",stdin);
    //freopen("2194.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        P[i].input();
    }
    sort(P + 1, P + n + 1);

    solve();

    return 0;
}
