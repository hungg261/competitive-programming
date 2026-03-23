/******************************************************************************
Link: https://cses.fi/problemset/task/2190
Code: 2190
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-00.22.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define double long double

namespace Geometry{

const double EPS = 1e-9;
struct Point{
    double x, y;

    Point(){}
    Point(double _x, double _y): x(_x), y(_y){}

    void input(){
        cin >> x >> y;
    }

    Point operator + (const Point& other) const{
        return {x + other.x, y + other.y};
    }

    Point operator - (const Point& other) const{
        return {x - other.x, y - other.y};
    }

    Point operator * (double k) const{
        return {x * k, y * k};
    }
};

double dot(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}

double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

int sign(double x){
    if(fabs(x) < EPS) return 0;
    return x > 0 ? 1 : -1;
}

int orientation(Point a, Point b, Point c){
    return sign(cross(b - a, c - a));
}

bool onSegment(Point p, Point A, Point B){
    return orientation(p, A, B) == 0 &&
        min(A.x, B.x) <= p.x && p.x <= max(A.x, B.x) &&
        min(A.y, B.y) <= p.y && p.y <= max(A.y, B.y);
}

bool intersect(Point A, Point B, Point C, Point D){
    int o1 = orientation(A, C, D), o2 = orientation(B, C, D);
    int o3 = orientation(C, A, B), o4 = orientation(D, A, B);

    if(o1 != o2 && o3 != o4) return true;

    return onSegment(C, A, B) || onSegment(D, A, B) || onSegment(A, C, D) || onSegment(B, C, D);
}

}
using namespace Geometry;

void solve(){
    Point A, B, C, D;
    A.input();
    B.input();
    C.input();
    D.input();

    cout << (intersect(A, B, C, D) ? "YES\n" : "NO\n");
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2190.INP","r",stdin);
    //freopen("2190.OUT","w",stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
