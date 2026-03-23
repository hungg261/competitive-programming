/******************************************************************************
Link: https://cses.fi/problemset/task/2193
Code: 2193
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-16.11.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

namespace Geometry{

const double EPS = 1e-9;
struct Point{
    int x, y;

    Point(){}
    Point(int _x, int _y): x(_x), y(_y){}

    void input(){
        cin >> x >> y;
    }

    Point operator + (const Point& other) const{
        return {x + other.x, y + other.y};
    }

    Point operator - (const Point& other) const{
        return {x - other.x, y - other.y};
    }

    Point operator * (int k) const{
        return {x * k, y * k};
    }
};

int dot(Point a, Point b){
    return a.x * b.x + a.y * b.y;
}

int cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

int sign(int x){
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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2193.INP","r",stdin);
    //freopen("2193.OUT","w",stdout);
    int n;
    cin >> n;

    vector<Point> pts(n + 1);
    for(int i = 0; i < n; ++i) pts[i].input();
    pts[n] = pts[0];

    int b = 0;
    int S2 = 0;
    for(int i = 0; i < n; ++i){
        Point v = pts[i] - pts[i + 1];

        b += __gcd(llabs(v.x), llabs(v.y));
        S2 += (pts[i].y + pts[i + 1].y) * (pts[i].x - pts[i + 1].x);
    }

    S2 = llabs(S2);
    int i = (S2 + 2 - b) / 2;

    cout << i << ' ' << b << '\n';

    return 0;
}
