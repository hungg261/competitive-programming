/******************************************************************************
Link: https://cses.fi/problemset/task/2189
Code: 2189
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-25-00.06.19
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

}
using namespace Geometry;

void solve(){
    Point A, B, C;
    A.input();
    B.input();
    C.input();

    int o = orientation(C, B, A);
    if(o == 0){
        cout << "TOUCH\n";
    }
    else if(o == 1){
        cout << "RIGHT\n";
    }
    else{
        cout << "LEFT\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2189.INP","r",stdin);
    //freopen("2189.OUT","w",stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
