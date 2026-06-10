/******************************************************************************
Link: https://cses.fi/problemset/task/2195
Code: 2195
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-26-14.11.31
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

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

bool cmpLess(const Point& a, const Point& b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void solve(){
    int n;
    cin >> n;

    vector<Point> pts(n);
    for(int i = 0; i < n; ++i){
        pts[i].input();
    }

    sort(begin(pts), end(pts), cmpLess);

    auto half = [&](){
        vector<Point> convex;
        for(int i = 0; i < n; ++i){
            int sz = convex.size();
            while(sz >= 2 && orientation(convex[sz - 2], convex[sz - 1], pts[i]) > 0)
                convex.pop_back(), --sz;
            convex.push_back(pts[i]);
        }

        return convex;
    };


    vector<Point> cv1 = half(); cv1.pop_back();
    reverse(begin(pts), end(pts));
    vector<Point> cv2 = half(); cv2.pop_back();

    cout << (int)(cv1.size() + cv2.size()) << '\n';
    for(Point p: cv1){
        cout << p.x << ' ' << p.y << '\n';
    }
    for(Point p: cv2){
        cout << p.x << ' ' << p.y << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2195.INP","r",stdin);
    //freopen("2195.OUT","w",stdout);

    solve();

    return 0;
}
