/******************************************************************************
Link: https://cses.fi/problemset/task/2192
Code: 2192
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-09.08.20
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

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
    int n, m;
    cin >> n >> m;

    vector<Point> p(n);
    for(Point& x: p) x.input();
    p.push_back(p[0]);

    double S = 0;
    for(int i = 0; i < n; ++i){
        S += (p[i].x * p[i + 1].y - p[i + 1].x * p[i].y);
    }

    while(m--){
        [&](){
            Point O;
            O.input();

            Point L(1e14, O.y);
            int inside = 0;
            for(int i = 0; i < n; ++i){
                if(onSegment(O, p[i], p[i + 1])){
                    cout << "BOUNDARY\n";
                    return;
                }

                if(
                    sign(cross(p[i] - O, p[i + 1] - O)) != 0 &&
                    intersect(O, L, p[i], p[i + 1])){


                    if(sign(O.y - p[i].y) == 0 && orientation(O, L, p[i + 1]) == 1 ||
                       sign(O.y - p[i + 1].y) == 0 && orientation(O, L, p[i]) == 1 ||
                       sign(O.y - p[i].y) * sign(O.y - p[i + 1].y) != 0)
                        inside ^= 1;
                }
            }

            if(inside & 1){
                cout << "INSIDE\n";
            }
            else{
                cout << "OUTSIDE\n";
            }
        }();
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2192.INP","r",stdin);
    //freopen("2192.OUT","w",stdout);

    solve();

    return 0;
}
