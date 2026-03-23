#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

const double pi = acos(-1);
inline double to_rad(double value){ return value * pi / 180.0; }
inline double to_deg(double value){ return value * 180.0 / pi; }
inline int sq(int x){ return x * x; }
inline double sq(double x){ return x * x; }

struct Point{
    int x, y;

    void input(){
        cin >> x >> y;
    }

    int sqdist(const Point& other) const{
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }

    double dist(const Point& other) const{
        return sqrt(sqdist(other));
    }

    bool operator == (const Point& other) const{
        return x == other.x && y == other.y;
    }

    int cross(const Point& other) const{
        return x * other.y - other.x * y;
    }
};

struct Circle{
    Point O;
    int r;

    void input(){
        O.input();
        cin >> r;
    }
};

double solve(const Circle& O1, const Circle& O2){
    double d = hypotl(O1.O.x - O2.O.x, O1.O.y - O2.O.y);
    double theta = 2 * acos((sq(O1.r) + sq(d) - sq(O2.r)) / (2.0 * O1.r * d));

    double s = sq(O1.r) * theta / 2;
    double tria = sinl(theta) * sq(O1.r) / 2;

    return s - tria;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    Circle A, B;
    A.input();
    B.input();

    cout.precision(20);

    if(sq(A.r + B.r) <= A.O.sqdist(B.O)){
        cout << "0\n";
        return 0;
    }

    double res = solve(A, B) + solve(B, A);
    if(isnan(res)){
        res = sq(min(A.r, B.r)) * pi;
    }

    cout << res << '\n';

    return 0;
}
