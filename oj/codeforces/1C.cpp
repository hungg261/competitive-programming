/******************************************************************************
Link: https://codeforces.com/contest/1/problem/C
Code: 1C
Time (YYYY-MM-DD-hh.mm.ss): 2026-07-10-10.22.31
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-4;
double gcd(double a, double b){
    if(b < EPS) return a;
    return gcd(b, a - b * floor(a / b));
}

struct Point{
    double x, y;

    friend istream& operator >> (istream& is, Point& p){
        return is >> p.x >> p.y;
    }
};

inline double pow2(double x){ return x * x; }
inline double dist(Point A, Point B){
    return sqrt(pow2(A.x - B.x) + pow2(A.y - B.y));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    Point A, B, C;
    cin >> A >> B >> C;

    double a = dist(A, B), b = dist(B, C), c = dist(C, A);

    double S = fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0;
    double R = a * b * c / (4 * S);

    const double PI = acos(-1);
    double oA = 2.0 * acos((pow2(b) + pow2(c) - pow2(a)) / (2.0 * b * c));
    double oB = 2.0 * acos((pow2(a) + pow2(c) - pow2(b)) / (2.0 * a * c));
    double oC = 2.0 * PI - oA - oB;

    double x = gcd(gcd(oA, oB), oC);
    double n = 2.0 * PI / x;

    double res = pow2(R) * sin(x) / 2 * n;
    cout << fixed << setprecision(10) << res << "\n";

    return 0;
}
